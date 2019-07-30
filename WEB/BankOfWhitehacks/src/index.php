

<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
	<title></title>
</head>
<body>
	<div class="container">

	  <div class="row">
	  	<div class="col-sm">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	    <div class="col-sm">
	    	<?php
	
				if(isset($_POST['deposit'])){
					$amount = $_POST['deposit'];
					$amount = intval($amount);
					if($amount > 1336){
						$result = ["flag"=>"WH2019{1npuT_r4ng3_v4L1dation_1s_1mp0t4nt}"];
						
						echo "<div class=\"alert alert-success\" role=\"alert\">
						  <center>".$result['flag']."<center>
						  	<img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						</div>";
					}else{
						$result = ["message"=>"You do not have enough money. You at least 1337!"];
						echo "<div class=\"alert alert-danger\" role=\"alert\">
						  <center>".$result['message']."<center>
						  	<img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						</div>";
					}
				}
				else{
					echo "<div class=\"alert alert-primary\" role=\"alert\">
						  <center>BANK OF WHITEHACKS<center><br>
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						    <img src=\"money.png\" height=\"150\" width=\"100\">
						</div>";
				}
			?>
			
	    </div>
	    <div class="col-sm">
	    	<img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	  </div>
	  <div class="row">
	    <div class="col-sm">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	    <div class="col-sm">
		    <form method="POST">
				Amount to deposit:
				<select name="deposit" class="custom-select">
					<option value="1">$1</option>
					<option value="2">$2</option>
				</select>
				<input type="submit" name="" value="Deposit">
			</form>
	    </div>
	    <div class="col-sm">
		<img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	  </div>
	  <div class="row">
	    <div class="col-sm">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	    <div class="col-sm">
		    <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	    <div class="col-sm">
		<img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	      <img src="money.png" height="150" width="100">
	    </div>
	  </div>
	</div>

	
</body>
</html>