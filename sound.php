<?php

$today = date("Y-m-d h:i:s");

$record = $today . ", Peaks: " . $_POST["peaks"] . ", Max dB Value: " . $_POST["max"] . "\n";

$file = "snd.log";	
if(file_exists($file))
	$fp = fopen($file, "a");	
else
	$fp = fopen($file, "w");	
fwrite($fp, $record);
fclose($fp);

?> 

