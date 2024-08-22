<?php
echo " While Loop";
echo "<br>";
$i = 1;
while ($i < 6) {
    echo $i;
    $i++;
}
$d = 10;
echo "<br>";
echo "<br>";
echo "<br>";
echo "Do while Loop";
echo "<br>";
do {
    echo $d ."\t";
    $d++;
} while ($d < 16);
echo "<br>";
echo "<br>";
echo "<br>";

echo "For Loop";
echo "<br>";

for ($x = 0; $x <= 10; $x++) {
    echo "The number is: $x <br>";
}
echo "<br>";
echo "<br>";
echo "<br>";
$colors = array("red", "green", "blue", "yellow");

echo "For Each Loop";
echo "<br>";
foreach ($colors as $x) {
  echo "$x <br>";
}
?>
