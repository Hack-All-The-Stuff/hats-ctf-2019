

<!DOCTYPE html>
<html>
<?php 
	$r = [];
	if(!empty($_GET['q']) && isset($_GET['submit'])){
		sleep(1);
		$myPDO = new PDO('sqlite:./blidedbytheloveforsqlohohoh.db');
		$result = $myPDO->query("SELECT name,description FROM user where id='".$_GET['q']."'");
	    foreach($result as $row)
	    {
	    	$r[] = $row;
	    #	var_dump($row);

    	}
    	if (sizeof($r) > 0){
    		echo "Wakanda";
    	}

	}
?>
<head>
	<title></title>
</head>
<body>
	<h1>Union SQL</h1>
	<br>
	<p>Try searching for the flag!!!</p>
	<br>
	<form>
		Search Query: <input type="text" name="q"><input type="submit" name="submit">
	</form>
</body>
</html>

