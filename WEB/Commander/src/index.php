

<!DOCTYPE html>
<html>
<?php 
	if(isset($_GET['SRC'])){
		show_source("index.php");
		die();
	}
	$cmd = base64_decode($_GET['cmd']);
	if(!$cmd){
		echo "ONLY BASE 64!";
	}
	else{
		$output = shell_exec("echo ". $cmd);
		echo "<pre>$output</pre>";	
	}

?>
<head>
	<title></title>
</head>
<body>
	COMMANDER<br>
	GET me a 'cmd'<br>
	You can also GET 'SRC' if you want to..
</body>
</html>

