#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Option
{
  char optionText[50];
  char optionLetter;
  struct Option *next;
} Option;


typedef struct Question
{
  char questionText[100];
  Option *options; // Linked list of options
  char correctOption;
} Question;

// Function to create a new option
Option *createOption(char text[], char letter)
{
  Option *newOption = (Option *)malloc(sizeof(Option));
  strcpy(newOption->optionText, text);
  newOption->optionLetter = letter;
  newOption->next = NULL;
  return newOption;
}

// Function to add an option to the linked list
void addOption(Option **head, char text[], char letter)
{
  Option *newOption = createOption(text, letter);

  // Find the last option and add the new option at the end
  if (*head == NULL)
  {
    *head = newOption;
  }
  else
  {
    Option *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newOption;
  }
}

// Function to create a new question
Question createQuestion(char text[], char correctOption, char options[][50])
{
  Question newQuestion;
  strcpy(newQuestion.questionText, text);
  newQuestion.correctOption = correctOption;

  // Create a linked list of options in order (A, B, C, D)
  newQuestion.options = NULL;
  for (char optionLetter = 'A'; optionLetter <= 'D'; ++optionLetter)
  {
    addOption(&newQuestion.options, options[optionLetter - 'A'], optionLetter);
  }

  return newQuestion;
}

// Function to display a question and its options
void displayQuestion(Question *question)
{
  printf("%s\n", question->questionText);

  Option *current = question->options;
  while (current != NULL)
  {
    printf("%c. %s\n", current->optionLetter, current->optionText);
    current = current->next;
  }

  printf("Your answer: ");
}

// Function to play the quiz
int playQuiz(Question questions[], int numQuestions)
{
  int score = 0;
  for (int i = 0; i < numQuestions; ++i)
  {
    displayQuestion(&questions[i]);
    char userAnswer;
    scanf(" %c", &userAnswer);
    if (userAnswer == questions[i].correctOption)
    {
      printf("Correct!\n");
      score++;
    }
    else
    {
      printf("Incorrect. The correct answer is %c\n", questions[i].correctOption);
    }
    printf("\n");
  }
  return score;
}

int main()
{
  system("cls");
  char c;
  int choice;
  int score = 0;
  bool play = true;
  printf(
      "________        .__           ________                       \n"
      "\\_____  \\  __ __|__|_______  /  _____/_____    _____   ____  \n"
      " /  / \\  \\|  |  \\  \\___   / /   \\  ___\\__  \\  /     \\_/ __ \\ \n"
      "/   \\_/.  \\  |  /  |/    /  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ \n"
      "\\______ \\_/____/|__/_____ \\  \\______  (____  /__|_|  /\\___  >\n"
      "       \\__>              \\/         \\/     \\/      \\/     \\/ \n");
  do
  {

    printf("Enter p to play:");
    scanf(" %c", &c);
    system("cls");
    if (c == 'p')
    {
      while (play)
      {
        // Define quiz questions and options
        char options1[][50] = {"London", "Kathmandu", "Paris", "New York"};
        char options2[][50] = {"C", "C++", "Python", "None of the Above"};
        char options3[][50] = {"2", "4", "6", "8"};
        char options4[][50] = {" Red", " Blue", " Green", " Yellow"};
        char options5[][50] = {" Cat", " Dog", " Bird", " Fish"};

        Question questions[] = {
            createQuestion("What is the capital of France?", 'C', options1),
            createQuestion("Which programming language is this program written in?", 'A', options2),
            createQuestion("What is the square root of 16?", 'B', options3),
            createQuestion("What color is the sky?", 'B', options4),
            createQuestion("What is a common pet?", 'B', options5),
        };

        // Play the quiz
        int totalScore = playQuiz(questions, sizeof(questions) / sizeof(questions[0]));
        system("cls");
        // Display total score and correct answers
        printf("Total Score: %d\n", totalScore);

        printf("Correct Answers:\n");
        for (int i = 0; i < sizeof(questions) / sizeof(questions[0]); ++i)
        {
          printf("%d. %c\n", i + 1, questions[i].correctOption);
        }
        printf("\n");
        printf("Do you want to play again?\n");
        printf("Enter 1 to play again..\n");
        printf("Enter 2 to quit..\n");
        scanf("%d", &choice);
        system("cls");
        if (choice == 1)
        {
          play = true;
        }
        else
        {
          printf("Thanks for playing!!\n");
          play = false;
          return 0;
        }
      }
    }
    else
    {
      printf("Invalid Choice!!");
    }
  } while (c != 'c');

  return 0;
}
