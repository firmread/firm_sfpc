var http = require('http');

//js everything is an object,, include functions
//start with something small and includes layers and layers of it
//they dont' have to know each other
http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.write(req.head:rs['user-agent']);
  res.end('Hello World\n');
}).listen(1337, '0.0.0.0');

//anonemous functions

/*
another style

var send_hello_world = fucntion(req,res){
	res.send('hello world\n');
}

http.createServer(send_hello_world).listen(1337, '127.0.0.1');


*/


console.log('Server running at http://127.0.0.1:1337/');