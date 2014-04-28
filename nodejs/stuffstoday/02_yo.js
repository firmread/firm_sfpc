var request = require('request');
var secret_key = "oRqPkVYVOpLWjIBWm4xmT7mxBUSaJgbG8vsYVWhB";
var url = 'https://api.data.gov/nrel/alt-fuel-stations/v1/nearest.json?api_key=' + secret_key + 'oRqPkVYVOpLWjIBWm4xmT7mxBUSaJgbG8vsYVWhB&location=Denver+CO';

request.get({url:url, json:true}, function (error, response, nearest_stations) {
  if (!error && response.statusCode == 200) {
  	var first_station =  nearest_stations.fuel.stations[0];
  	console.log("latitude: " + first_station.latitude);
  	console.log("longtitude: " + first_station.longtitude);
    // console.log(body) // Print the google web page.
  }
});


