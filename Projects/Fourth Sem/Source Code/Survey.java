import java.sql.*;
import java.util.Scanner;

public class Survey {

    public static void main(String[] args) {
        Connection connection = null;
        Scanner scanner = new Scanner(System.in);

        try {
            // Connect to the database
            String url = "jdbc:mysql://localhost:3306/my_db";
            String userName = "root";
            String password = "root";
            connection = DriverManager.getConnection(url, userName, password);
    
            // Create tables if they do not exist
            createTable(connection, "CREATE TABLE IF NOT EXISTS Users (ID INT AUTO_INCREMENT PRIMARY KEY, Username VARCHAR(255), Password VARCHAR(255), Role ENUM('admin', 'user') NOT NULL, Address VARCHAR(255))");
            createTable(connection, "CREATE TABLE IF NOT EXISTS Surveys (SurveyID INT AUTO_INCREMENT PRIMARY KEY, Title VARCHAR(255), Description TEXT)");
            createTable(connection, "CREATE TABLE IF NOT EXISTS Questions (QuestionID INT AUTO_INCREMENT PRIMARY KEY, SurveyID INT, QuestionText TEXT, FOREIGN KEY (SurveyID) REFERENCES Surveys(SurveyID))");
            createTable(connection, "CREATE TABLE IF NOT EXISTS Responses (ResponseID INT AUTO_INCREMENT PRIMARY KEY, QuestionID INT, UserID INT, Answer TEXT, FOREIGN KEY (QuestionID) REFERENCES Questions(QuestionID), FOREIGN KEY (UserID) REFERENCES Users(ID))");

            // User operations
            System.out.println("1. Login\n2. Register");
            System.out.print("Choose an option: ");
            int initChoice = Integer.parseInt(scanner.nextLine());
            User user = null;

            if (initChoice == 1) {
                user = loginUser(scanner, connection);
            } else if (initChoice == 2) {
                registerUser(scanner, connection);
                user = loginUser(scanner, connection);
            }

            if (user == null) {
                System.out.println("Authentication failed!");
                return;
            }

            // Main menu
            while (true) {
                System.out.println("1. Create Survey");
                System.out.println("2. Participate in Survey");
                System.out.println("3. View Survey Results");
                System.out.println("4. Exit");
                System.out.print("Choose an option: ");
                int choice = Integer.parseInt(scanner.nextLine());

                switch (choice) {
                    case 1:
                        if ("admin".equals(user.getRole())) {
                            createSurvey(scanner, connection);
                        } else {
                            System.out.println("Only admin can create surveys.");
                        }
                        break;
                    case 2:
                        participateInSurvey(scanner, connection, user.getId());
                        break;
                    case 3:
                        viewSurveyResults(scanner, connection);
                        break;
                    case 4:
                        System.out.println("Exiting program.");
                        return;
                    default:
                        System.out.println("Invalid choice. Please choose again.");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (connection != null) connection.close();
                scanner.close();
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    private static void createTable(Connection connection, String sql) throws SQLException {
        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.executeUpdate();
        }
    }

    private static User loginUser(Scanner scanner, Connection connection) throws SQLException {
        System.out.println("Enter Username:");
        String username = scanner.nextLine();
        System.out.println("Enter Password:");
        String password = scanner.nextLine();

        String sql = "SELECT ID, Username, Role FROM Users WHERE Username = ? AND Password = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, username);
            preparedStatement.setString(2, password);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (resultSet.next()) {
                    return new User(resultSet.getInt("ID"), username, resultSet.getString("Role"));
                } else {
                    System.out.println("Login failed, please check your username and password.");
                }
            }
        }
        return null;
    }

    private static void registerUser(Scanner scanner, Connection connection) throws SQLException {
        System.out.println("Enter a new Username:");
        String username = scanner.nextLine();
        System.out.println("Enter a Password:");
        String password = scanner.nextLine();
        System.out.println("Enter Role (admin/user):");
        String role = scanner.nextLine();
        System.out.println("Enter Address:");
        String address = scanner.nextLine();

        String sql = "INSERT INTO Users (Username, Password, Role, Address) VALUES (?, ?, ?, ?)";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sql)) {
            preparedStatement.setString(1, username);
            preparedStatement.setString(2, password);
            preparedStatement.setString(3, role);
            preparedStatement.setString(4, address);
            preparedStatement.executeUpdate();
        }
        System.out.println("User registered successfully.");
    }

    private static void createSurvey(Scanner scanner, Connection connection) throws SQLException {
        System.out.println("Enter Survey Title:");
        String title = scanner.nextLine();
        System.out.println("Enter Survey Description:");
        String description = scanner.nextLine();

        String sqlInsertSurvey = "INSERT INTO Surveys (Title, Description) VALUES (?, ?)";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlInsertSurvey, Statement.RETURN_GENERATED_KEYS)) {
            preparedStatement.setString(1, title);
            preparedStatement.setString(2, description);
            preparedStatement.executeUpdate();

            try (ResultSet generatedKeys = preparedStatement.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    long surveyId = generatedKeys.getLong(1);
                    System.out.println("Enter number of questions:");
                    int numQuestions = Integer.parseInt(scanner.nextLine());
                    for (int i = 0; i < numQuestions; i++) {
                        System.out.println("Enter question " + (i + 1) + ":");
                        String questionText = scanner.nextLine();
                        addQuestionToSurvey(connection, surveyId, questionText);
                    }
                }
            }
        }
        System.out.println("Survey created successfully!");
    }

    private static void addQuestionToSurvey(Connection connection, long surveyId, String questionText) throws SQLException {
        String sqlInsertQuestion = "INSERT INTO Questions (SurveyID, QuestionText) VALUES (?, ?)";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlInsertQuestion)) {
            preparedStatement.setLong(1, surveyId);
            preparedStatement.setString(2, questionText);
            preparedStatement.executeUpdate();
        }
    }

    private static void participateInSurvey(Scanner scanner, Connection connection, int userId) throws SQLException {
        System.out.println("Enter Survey ID to participate:");
        int surveyId = Integer.parseInt(scanner.nextLine());

        String sqlSelectQuestions = "SELECT QuestionID, QuestionText FROM Questions WHERE SurveyID = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlSelectQuestions)) {
            preparedStatement.setInt(1, surveyId);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (!resultSet.isBeforeFirst()) {
                    System.out.println("No questions found for this survey.");
                    return;
                }
                while (resultSet.next()) {
                    long questionId = resultSet.getLong("QuestionID");
                    String questionText = resultSet.getString("QuestionText");
                    System.out.println(questionText);
                    System.out.println("Enter your answer:");
                    String answer = scanner.nextLine();
                    recordResponse(connection, questionId, userId, answer);
                }
            }
        }
        System.out.println("Thank you for participating in the survey.");
    }

    private static void recordResponse(Connection connection, long questionId, int userId, String answer) throws SQLException {
        String sqlInsertResponse = "INSERT INTO Responses (QuestionID, UserID, Answer) VALUES (?, ?, ?)";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlInsertResponse)) {
            preparedStatement.setLong(1, questionId);
            preparedStatement.setInt(2, userId);
            preparedStatement.setString(3, answer);
            preparedStatement.executeUpdate();
        }
    }

    private static void viewSurveyResults(Scanner scanner, Connection connection) throws SQLException {
        System.out.println("Enter Survey ID to view results:");
        int surveyId = Integer.parseInt(scanner.nextLine());

        String sqlSelectResponses = "SELECT Q.QuestionText, R.Answer FROM Responses R INNER JOIN Questions Q ON R.QuestionID = Q.QuestionID WHERE Q.SurveyID = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlSelectResponses)) {
            preparedStatement.setInt(1, surveyId);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                if (!resultSet.isBeforeFirst()) {
                    System.out.println("No responses found for this survey.");
                    return;
                }
                while (resultSet.next()) {
                    String questionText = resultSet.getString("QuestionText");
                    String answer = resultSet.getString("Answer");
                    System.out.println(questionText + ": " + answer);
                }
            }
        }
    }
}

class User {
    private int id;
    private String username;
    private String role;

    public User(int id, String username, String role) {
        this.id = id;
        this.username = username;
        this.role = role;
    }

    public int getId() {
        return id;
    }

    public String getUsername() {
        return username;
    }

    public String getRole() {
        return role;
    }
}
