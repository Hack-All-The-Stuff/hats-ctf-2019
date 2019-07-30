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
		$f_array = explode(";", $cmd);
		$s_array = explode(" ", $f_array[1]);
		$forbidden = ['cat','less','more','head','tail','od','hexdump','echo','touch','>','<','>>','<<','|','\\','$','bash','sh','sed','awk'];
		foreach ($s_array as $value) {
			if(in_array($value, $forbidden)){
				echo "HACKER!";
				die();
			}
		}
		$output = shell_exec("echo ". $cmd);
		echo "<pre>$output</pre>";	
	}

?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	COMMANDER 2<br>
	HAH! I HAVE DEFENCES NOW!<br>
	GET me a 'cmd'<br>
	You can also GET 'SRC' if you want to..
</body>
</html>

