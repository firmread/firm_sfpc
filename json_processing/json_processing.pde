JSONObject json;
PImage img;
String image_url="";

void setup(){
  while(image_url == ""){
    json = loadJSONObject("http://scrapi.org/object/81781");
    image_url = json.getString("image");
  }
  img = loadImage(image_url);
  size(img.width/4, img.height/4);
}

void draw(){
  image(img,0,0,img.width/4, img.height/4);
}


