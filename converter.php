<?php
	if (isset($argc)) {
		$steamId = $argv[1];
		$dayZGUID = base64_encode(hash("sha256", $steamId,true));
		echo('Your dayZGUID is : '.$dayZGUID);
	}else{
		echo('Expecting 1 parameter being STEAMID64');
	}

?>