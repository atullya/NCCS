<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "Test";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Query to select data from the student table
$sql = "SELECT * FROM student";
$result = mysqli_query($conn, $sql);
?>
<table border="1">
    <tr>
        <th>SID</th>
        <th>Name</th>
        <th>Address</th>
    </tr>
    <tbody>
<?php
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        echo '<tr>
                <td>' . $row['sid'] . '</td>
                <td>' . $row['sname'] . '</td>
                <td>' . $row['address'] . '</td>
              </tr>';
    }
} else {
    echo '<tr><td colspan="3">No data found</td></tr>';
}

// Close connection
mysqli_close($conn);
?>
    </tbody>
</table>
