#include "sdogica.h"
using namespace std;
int opt=0;
int opt2=0;
int nrterm=1;
int CX = 0;
int CY = 110;
int SY=WINDOW_HEIGHT-100;
bool mode=false; //false: ce vrei? true: cum vrei?
char scris[999];
char scris2[999]={' '};
bool OK=false; //Ca la scoala, frate! Verifica daca algoritmul a gasit daca termenul este in relatie cu un altul.
int hi = -1;

struct Term{
	int x;
	int y;
	int di;
	short poz[100]; //poz=rel
	bool contr=false;
		
	



};
ifstream in("entry.in");  //fisierul
ofstream out("exit.out");
Term term[100]; //limita termenilor teoretici este de 101


void clearscris(){
 for(int i=0;i<100;i++) scris[i] = ' ';
 opt=0;
 
 for(int i=0;i<100;i++) scris2[i] = ' ';
 opt2=0;

}

void clearterm(){
 for(int i=0;i<nrterm;i++){
	term[i].x = 0;
	term[i].y = 0;
	term[i].di = 0;
	term[i].contr = false;
	for(int j=0;j<100;j++){
		term[i].poz[j]=0;
	CY=110;
	CX=0;
}
	
	

}
	nrterm = 1;
}


void CreateWindow() {
    Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (!Window)
        std::cout << "There was a problem creating the window.";
    Renderer = SDL_CreateRenderer(Window, -1, 0);
    if (!Renderer)
        std::cout << "There was a problem creating the renderer.";
}

void CreateText(const char* message, int x, int y, const char* font_name,  int font_size, SDL_Texture* &TextTexture, SDL_Rect &TextRect,    Uint8 R=255, Uint8 G=255, Uint8 B=255, Uint8 A=255) {
    TTF_Init();
    TTF_Font *font = TTF_OpenFont(font_name, font_size);
    if (!font)
        std::cout << "Couldn't find/init open ttf font named " <<font_name<<std::endl;
    TextSurface = TTF_RenderText_Solid(font, message, {R, G, B, A});
    TextTexture = SDL_CreateTextureFromSurface(Renderer, TextSurface);
    TextRect.x = x; // Center horizontaly
    TextRect.y = y; // Center verticaly
    TextRect.w = TextSurface->w;
    TextRect.h = TextSurface->h;

    
    // After you create the texture you can release the surface memory allocation because we actually render the texture not the surface.
    SDL_FreeSurface(TextSurface);
    

    TTF_Quit();
}


//Note to whoever it may concern : the last two ifs in "case:SDL_KEYDOWN" do not do the same thing (it took me 10 minutes to realize this).

bool IsPollingEvent() {
    while(SDL_PollEvent(&WindowEvent)) {
	
        switch (WindowEvent.type) {
            case SDL_QUIT:
		 return false;
	    case SDL_KEYDOWN:
		if (WindowEvent.key.keysym.sym >= 33 && WindowEvent.key.keysym.sym <= 126) {
 		if(!mode){
			
			scris[opt]=(char)WindowEvent.key.keysym.sym;
			opt++;
		
		}
        	else{
			scris2[opt2]=(char)WindowEvent.key.keysym.sym;
			opt2++;
		}
    }
		if(WindowEvent.key.keysym.sym == SDLK_BACKSPACE){
			if(!mode){
			if(opt>0) opt--;
			scris[opt] = ' ';
			}
			else{
			if(opt2>0) opt2--;
			scris2[opt2] = ' ';
			}
}
		if(WindowEvent.key.keysym.sym == SDLK_SPACE){
		if(!mode){
				
			scris[opt] = ' ';
			opt++;
		}
		else{
			scris2[opt2] = ' ';
			opt2++;
		}

}
	 if(WindowEvent.key.keysym.sym == SDLK_RETURN){
		if(!mode) mode=true;	 
			else{
				check();
				clearscris();
				mode=false;
				
    		CreateText(scris, 0, SY, "cmd.ttf", 15, title, rtitle);
		CreateText(scris2, 0, SY+13, "cmd.ttf", 15, open, ropen);	
		Render();
}
}
		
    		CreateText(scris, 0, SY, "cmd.ttf", 15, title, rtitle);
	if(mode)	CreateText(scris2, 0, SY+13, "cmd.ttf", 15, open, ropen);	
			
		break;
	   default:
		break; 
        }
	WindowEvent.type = -1;
    }
    return true;
}


void point(float x, float y){
	SDL_RenderDrawPointF(Renderer, x, y);
}

 void line(float x1, float y1, float x2, float y2){
             float dx = x2-x1;
             float dy = y2 - y1;
             float length = std::sqrt(dx*dx+dy*dy);
             float angle = std::atan2(dy, dx);
             for(float i=0;i<length;i++){
                            SDL_RenderDrawPointF(Renderer, x1+std::cos(angle)*i, y1 + std::sin(angle)*i);
             }
           
  };

void circle(int32_t centreX, int32_t centreY,
      int32_t diameter, int32_t parts=8){
 
 
      int32_t x = (diameter/2 - 1);
      int32_t y = 0;
      int32_t tx = 1;
      int32_t ty = 1;
      int32_t error = (tx - diameter);
 
 
      while (x >= y)
      {
         //  Each of the following renders an octant of the circle
        if(parts>=1)
             SDL_RenderDrawPointF(Renderer, centreX+x, centreY-y);
        if(parts>=2)
             SDL_RenderDrawPointF(Renderer, centreX+x, centreY+y);
 
           // screen.pixel(centreX + x, centreY + y, vect);
      if(parts>=3)
             SDL_RenderDrawPointF(Renderer, centreX-x, centreY-y);
 
          //  screen.pixel(centreX - x, centreY - y, vect);
       if(parts>=4)
            SDL_RenderDrawPointF(Renderer, centreX-x, centreY+y);
       if(parts>=5)
           SDL_RenderDrawPointF(Renderer, centreX+y, centreY-x);
 
          //  screen.pixel(centreX + y, centreY - x, vect);
       if(parts>=6)
            SDL_RenderDrawPointF(Renderer, centreX+y, centreY+x);

         //  screen.pixel(centreX + y, centreY + x)
       if(parts>=7)
           SDL_RenderDrawPointF(Renderer, centreX-y,  centreY-x);

          // screen.pixel(centreX - y, centreY - x, vect);
       if(parts>=8)
           SDL_RenderDrawPointF(Renderer, centreX-y, centreY+x);
        //   screen.pixel(centreX - y, centreY + x, vect);

        if (error <= 0)
        {
           ++y;
           error += ty;
           ty += 2;
        }

        if (error > 0)
  {
          --x;
          tx += 2;
          error += (tx - diameter);
       }
    }
       
}


void check(){
	if (scris[0]=='t' && scris[1]=='e'){ //sper sa nu gaseasca nimeni ce am facut aici...
		term[nrterm].x = WINDOW_WIDTH/2;
		term[nrterm].y = WINDOW_HEIGHT/4-100;
		term[nrterm].di = 100;
		term[nrterm].poz[nrterm] = 1; //un termen in raport cu el insusi are raport de identitate.
		cout<<'t';
	if(scris2[0]!=' '){
		for(int i=0;i<=opt2;i+=4){
			term[nrterm].poz[(int)scris2[i]-48] = (int)scris2[i+2]-48; // poz = rel
			cout<<(int)scris2[i]-48<<(int)scris2[i+2]-48<<endl;
		}

}
	else cout<<-1<<-1<<endl;
	
	
		for(int j=0; j<=nrterm;j++){
			if(term[nrterm].poz[j] == 3){
				term[nrterm].x += term[j].di/2; OK=true; term[nrterm].y = term[j].y;
				
			} 
			if(term[nrterm].poz[j] == 1){
				term[nrterm].x = term[j].x;term[nrterm].y =term[j].y; 
				if(scris2[0]!=' ') OK=true;
			}
			if(term[nrterm].poz[j] == 2){
				term[nrterm].x = term[j].x-5; OK=true; term[nrterm].y =term[j].y;
				 term[nrterm].di=term[j].di/2;
			}
			if(term[nrterm].poz[j] == 4){
				term[nrterm].x = term[j].x; OK=true; term[nrterm].y =term[j].y;
				term[j].contr = true;
			}
}

			
		if(!OK && nrterm!=1){ term[nrterm].y+=CY; CY+=110; }
	
		OK=false;
		nrterm++;	
}
		
		if(scris[0]=='h' && scris[1]=='i')
			hi = int(scris2[0])-48;
		if(scris[0]=='f' && scris[1]=='i' && scris[2]=='s'){
			char i;
			int a, b;
			clearterm();
			while(in>>i && in>>a && in>>b){
				clearscris();
				if(a == -1 && b == -1){
					//scris={'t', 'e'};
				//	scris2={' '};
					scris[0] = 't';
					scris[1] = 'e';
					scris2[0] = ' ';
					opt=2;
					check(); 	
				}
				if(b==1){
				//	scris={'t', 'e'};
				//	scris2={(char(a+48)), '1'};
					scris[0] = 't';
					scris[1] = 'e';
					opt=2;
					scris2[0] = char(a+48);
					scris2[1] = ' ';
					scris2[2] = '1';
					opt2=3;
					check();
					
				}
				if(b==2){
				//	scris={'t', 'e'};
				//	scris2={(char(a+48)), '2'};
					
					scris[0] = 't';
					scris[1] = 'e';
					opt=2;
					scris2[0] = char(a+48);
					scris2[1] = ' ';
					scris2[2] = '2';
					opt2=3;
					check();
					
				}
				if(b==3){
				//	scris={'t', 'e'};
				//	scris2={(char(a+48)), '3'};
					
					scris[0] = 't';
					scris[1] = 'e';
					opt=2;
					scris2[0] = char(a+48);
					scris2[1] = ' ';
					scris2[2] = '3';
					opt2=3;
					check();
					
				}
				if(b==4){
				//	scris={'t', 'e'};
				//	scris2={(char(a+48)), '4'};				
					
					scris[0] = 't';
					scris[1] = 'e';
					opt=2;
					scris2[0] = char(a+48);
					scris2[1] = ' ';
					scris2[2] = '4';
					opt2=3;
					check();
					
				}
				
				
				
			}

}
	
		if(scris[0]=='i' && scris[1]=='e'){
			ClearMemory();
			system("./menu");
			exit(0);
}
		if(scris[0]=='s' && scris[1]=='t'){
			clearterm();
}

	clearscris();
	     
	}

	







void Render() {
    SDL_RenderClear(Renderer);
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255); //culoarea background-ului
    SDL_RenderCopy(Renderer, title, NULL, &rtitle);
    SDL_RenderCopy(Renderer, open, NULL, &ropen);
    line (0, WINDOW_HEIGHT-105, WINDOW_WIDTH, WINDOW_HEIGHT-105);  

    for(int i=0;i<=nrterm;i++){
	if(!term[i].contr) circle(term[i].x, term[i].y, term[i].di);
		else line(term[i].x-term[i].di/3, term[i].y-term[i].di/3, term[i].x+term[i].di/3, term[i].y+term[i].di/3);
//	cout<<term[i].x<<" "<<term[i].y<<" "<<term[i].di<<endl;
		
	
}
		
	
	  if(hi!=-1){
		SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
		circle(term[hi].x, term[hi].y, term[hi].di);
	
}
	SDL_RenderPresent(Renderer);


   

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);  
	
   
  
}


void ClearMemory() {
    SDL_DestroyTexture(title);	
    SDL_DestroyTexture(open);
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    std::cout << "ClearMemory() function completed succcesfully" <<nrterm<<" "<<scris<<" "<<scris2<<std::endl;
    in.close();
    out.close();
}

int main() {
    CreateWindow();

//const char* message, int x, int y, const char* font_name,  int font_size, SDL_Texture* &TextTexture, SDL_Rect &TextRect,   
    while(IsPollingEvent()){
    Render();
    
	
	}

  std::cout<<scris2<<std::endl;    
    ClearMemory();
    exit(0);
    return EXIT_SUCCESS;
}
