<?php
session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<?php


if(!empty($_POST['submit']) && isset($_POST['submit']) && isset($_SESSION['time_now'])){
	$var = $_POST['submit'];
	$b = microtime(true);
	$c = $b - $_SESSION['time_now'];
	if($c < 0.5){
		if($var === $_SESSION['question']){
			echo 'WH2019{1_l0v3_c4ptch4!!!!!}';
		}
		else{
			echo "WRONG";
			unset($_SESSION['time_now']);
		}
	}
	else{
		echo "Too late";
		unset($_SESSION['time_now']);
	}
}	
else{
		$_SESSION['time_now'] = microtime(true);
		$str = "";
		for($i=0;$i<51;$i++){
			$j = rand(65,90);
			$str .= chr($j);
		}
		$_SESSION['question'] = $str;
		echo "<div class=\"captcha\">CAPTCHA: ".$str."</div>";
		echo "<br>";
		$dis_time = "0.";
		$str_a = str_split($str);
		foreach($str_a as $char){
			$dis_time .= ord($char);
		}
		echo "<p>Enter the CAPTCHA under: " . $dis_time."sec";
}



//$a = microtime(true);
//sleep(1.2);
/*$now = microtime(true);
$c = $b - $a;
echo $a;
echo "<br>";
echo $b;
echo "<br>";
echo $c;
echo "<br>";
$str = "";
for($i=0;$i<51;$i++){
	$j = rand(65,90);
	$str .= chr($j);
}
echo $str;*/

?>


	<form method="POST">
		<input type="text" name="submit">
		<input type="submit" name="s">
	</form>
</body>
</html>