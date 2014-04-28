server.listen(5200, function(){
	var stream;
	stream =  t.stream('statuses/filter', {track: ['sfpc']});

	stream.on('tweet', function(tweet){
		console.log(tweet);
	});
});