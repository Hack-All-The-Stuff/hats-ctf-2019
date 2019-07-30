<?php
if(isset($_GET['SRC'])){
	show_source("index.php");
	die();
}
require_once 'flag.php';
if(isset($_GET['flag'])){
	$var = $_GET['flag'];
	if($var == 1 && strlen($var) == 9){
			echo $flag;
		}
}

?>

<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	Truth shall unfold when I GET a SouRCe.<br>
	<!-- Try making a GET request for SRC ?-->
</body>
</html>
