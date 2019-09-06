<?php

if (isset($_GET['src'])) {
    highlight_file(__FILE__) and die();
}

  include 'secret.php';
  if($_GET["str1"] and $_GET["str2"]) {
    if ($_GET["str1"] !== $_GET["str2"] and
        hash("sha512", $salt . $_GET["str1"]) === hash("sha512", $salt . $_GET["str2"])) {
      echo $flag;
    } else {
      echo "Sorry, you're wrong.";
    }
    exit();
  }
?>

<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>NiftyHashing</title>
    <link href="https://fonts.googleapis.com/css?family=Audiowide" rel="stylesheet">
    <style media="screen">
      body{
        font-family: 'Audiowide', cursive;
        background-color: #fff;
        padding: auto;
        text-align: center;
      }
      input{
        margin:1rem;
      }
    </style>
  </head>
  <body>
    <h2>
      Nifty Hashing Algorithm. Only the ones who knows their basics will get through.
    </h2>
    <form method="GET">
      Value 1: <input type="text" name="str1">
      <br>
      Value 2: <input type="text" name="str2">
      <br>
      <input type="submit" value="submit">
    </form>
    <img src="ninja.png" alt="" height="300px" width="300px">
  </body>
</html>