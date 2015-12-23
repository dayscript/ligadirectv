<div class="video">
  <iframe type="text/html" width="300" height="320" src="http://www.youtube.com/embed/<?php
  	//print variable_get('video_home');
  	

	$xml = simplexml_load_file('https://www.youtube.com/feeds/videos.xml?user=LigaDirectv');

	if (!empty($xml->entry[0]->children('yt', true)->videoId[0])){
		$id = $xml->entry[0]->children('yt', true)->videoId[0];
	}

	echo $id; // Outputs the video ID.
  ?>" frameborder="0"></iframe>
</div>
