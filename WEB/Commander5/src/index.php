<?php 

	if(isset($_GET['SRC'])){
		show_source("index.php");
		die();
	}
	else{
		$cmd = $_GET['cmd'];
		$forbidden = ['bash','brltty','bunzip2','busybox','bzcat','bzcmp','base64','base32','bzdiff','bzegrep','bzexe','bzfgrep','bzgrep','bzip2','bzip2recover','bzless','bzmore','cat','chacl','chgrp','chmod','chown','chvt','cp','cpio','dash','date','dd','df','dir','dmesg','dnsdomainname','domainname','dumpkeys','echo','ed','efibootdump','efibootmgr','egrep','false','fgconsole','fgrep','findmnt','find','fuser','fusermount','getfacl','grep','gunzip','gzexe','gzip','hciconfig','hostname','ip','journalctl','kbd_mode','kill','kmod','less','lessecho','lessfile','lesskey','lesspipe','ln','loadkeys','login','loginctl','lowntfs-3g','ls','lsblk','lsmod','mkdir','mknod','mktemp','more','mount','mountpoint','mt','mt-gnu','mv','nano','nc','nc.openbsd','netcat','netstat','networkctl','nisdomainname','ntfs-3g','ntfs-3g.probe','ntfscat','ntfscluster','ntfscmp','ntfsfallocate','ntfsfix','ntfsinfo','ntfsls','ntfsmove','ntfsrecover','ntfssecaudit','ntfstruncate','ntfsusermap','ntfswipe','open','openvt','pidof','ping','ping4','ping6','plymouth','prettyping','ps','pwd','rbash','readlink','red','rm','rmdir','rnano','run-parts','searchsploit','sed','setfacl','setfont','setupcon','sh','sh.distrib','sleep','ss','static-sh','stty','su','sync','systemctl','systemd','systemd-ask-password','systemd-escape','systemd-hwdb','systemd-inhibit','systemd-machine-id-setup','systemd-notify','systemd-sysusers','systemd-tmpfiles','systemd-tty-ask-password-agent','tar','tempfile','touch','true','udevadm','ulockmgr_server','umount','uname','uncompress','unicode_start','vdir','wdctl','which','whiptail','ypdomainname','zcat','zcmp','zdiff','zegrep','zfgrep','zforce','zgrep','zless','zmore','znew','!','@','#','$','%','^','&','(',')','+','=','{','}','[',']','\\','|','<','<<','>','>>','`','~','``','cat','less','more','head','tail','od','tac','hexdump','echo','touch','usr','>','<','>>','<<','|','$','bash','sh','sed','awk','etc','root','home','var','lib','flag','txt','a','f','l','g','secrets'];
		$output_forbidden = ['..','f','9','2','0','1','H',9];
		foreach ($forbidden as $value) {
			
			if(strpos($cmd, $value)){
				echo "HACKER!";
				die();
			}
		}
		$output = shell_exec($cmd);
		foreach ($output_forbidden as $value) {			
			if(strpos($output, $value)){
				echo "HACKER!";
				die();
			}
		}
		echo "<pre>$output</pre>";	
	}

?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	COMMANDER 5<br>
	HAH! I HAVE WAFu NOW!<br>
	GET me a 'cmd'<br>
	You can also GET 'SRC' if you want to..
</body>
</html>

