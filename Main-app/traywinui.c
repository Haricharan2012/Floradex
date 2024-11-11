
#include "raylib.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#define MAX_INPUT_CHARS 12
#define TEMP 12


   typedef struct 
       {
          Texture2D medpic;
          char id[20];
        } medvar;


// Function to convert a string to lowercase
void strToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}


int k=0;
// Linear search function to find texture by ID (case-insensitive)
int searchTextureByID(medvar medarr[], int count, const char *id) {
    char tempID[20];
    char tempKey[20];
    
    strcpy(tempKey, id);       // Copy the search ID
    strToLower(tempKey);       // Convert search ID to lowercase for case-insensitive search
    
    for (int i = 0; i < count; i++) {
        strcpy(tempID, medarr[i].id);  // Copy the texture ID from the array
        strToLower(tempID);            // Convert texture ID to lowercase
        
        // Compare the lowercase strings
        if (strcmp(tempID, tempKey) == 0) {
            return i;  // Return index if found
        }
    }
    
    return -1;  // Return -1 if not found
}



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------


bool collision[50]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
Vector2 mousepos = {-100.0f, 100.0f};


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 500;
    
    const char *searchID;
    // int index=-1;
       // medvar medarr[5];

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
     InitAudioDevice();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    

     
   //-----------------------vectors-------------------------------//
   
   int buto=0;
   
   Vector2 startv={175,320};   
   Vector2 collecv={340,320};
   Vector2 searchv={500,320};
   Vector2 selecv={0,0};
   Vector2 bigselv={0,0};
   Vector2 infoselv={0,0};
   
   Vector2 tempselv={0,0};
   
   //--------buttons--------------------//
    bool Button001Pressed = false;
    bool Button002Pressed = false;
    bool Button004Pressed = false;
    bool Button005Pressed = false;
    bool Button006Pressed = false;
   //------------------------------------//
   
   
  
  int letterCount = 0;


  Rectangle textBox = {screenWidth / 2.0f - 100, 50, 225, 50};
  Rectangle dumbox = {screenWidth / 2.0f - 100, 50, 225, 50};

  bool mouseOnText = false;
  // input box//
  
  
   int framecounter = 0;
   
     
       
    //textures-------------------------------------------------------//
    Texture2D logo =LoadTexture("./floradex.png");     //loading logo texture
    Texture2D start=LoadTexture("./start.png");            //loading start  button
    Texture2D collec=LoadTexture("./collections.png");  //loadingcollections button
    Texture2D search=LoadTexture("./search.png");        //loading search button
    Texture2D screen2=LoadTexture("./blank.png");
    Texture2D collec_scr=LoadTexture("./blank.png");
    Texture2D back_collec=LoadTexture("./blank.png");
    Texture2D search_back=LoadTexture("./blank.png");
    Texture2D collec_grp=LoadTexture("./blank.png");
    Texture2D searchscreen=LoadTexture("./blank.png");   //loading search screen
    Texture2D plant1;
    Texture2D plant2;
    Texture2D plant3;
    Texture2D plant4;
    Texture2D plant5;
    Texture2D plant6;
    Texture2D plant7;
    Texture2D plant8;
    Texture2D plant9;
        Texture2D tempscr=LoadTexture("./blank.png");
      Texture2D temp=LoadTexture("./blankplant.png");
 
    Texture2D infoscr=LoadTexture("./blankplant.png");
    
    
    Texture2D tempinfo[2]={LoadTexture("./blankplant.png"),LoadTexture("./blankplant")};
    Texture2D tempmed=LoadTexture("./blankplant.png");
    
  
  
  Texture2D collecinfo[20];
    
 //----------------------------------info_textures------------------------------------------------------------------------------------------------------------------------------------------------//

    
    Texture2D infopl[25];
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


//------------------------------------plant_pictures----------------------------------------------------------------------------------------------------------------------------------------------//
   
   Texture2D plantpic[30];
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//


//----------------------------------buttons from 10-19--------------------------------------------------------------------------------------------------------------------------------------------//    
    
    Texture2D buttonx[15]={LoadTexture("./button10.png"),LoadTexture("./button11.png"),LoadTexture("./button12.png"),LoadTexture("./button13.png"),LoadTexture("./button14.png"),LoadTexture("./button15.png"),LoadTexture("./button16.png"),LoadTexture("./button17.png"),LoadTexture("./button18.png"),LoadTexture("./button19.png"),LoadTexture("./button20.png")};
   //--------------------------------______-------_____--------____________________________________________________________________________________________________________________-----------------// 
    
    
    Texture2D temppic[2]={LoadTexture("./plant1pic")};  //temporary picture
     Texture2D frame=LoadTexture("./blankplant.png");  //frame
     Texture2D selection=LoadTexture(".blankplant.png");   //selection overlay
     Texture2D bigsel=LoadTexture("./blankplant.png");  //big selection
     Texture2D infosel=LoadTexture("./blankplant.png");//infosel
     Texture2D sc1sel=LoadTexture("./blankplant.png");   
    
    
         
     Texture2D nextcol=LoadTexture("./blankplant.png");
     Texture2D prevcol=LoadTexture("./blankplanr.png");
   //-------------------------------------------------------------------//
   
    Sound buttonsound = LoadSound("./click.wav");   //button sound
    Sound click=LoadSound("./laser.mp3");           //test
   
   
   
   
      //--------------------rectangles----------------------------------------------//
   Rectangle srcrect;    //rectangle for start button
   Rectangle collecrect;  //rectangle for  collections button
   Rectangle searchrect;  //rectangle for search button
   Rectangle point;   //rectangle for mouse cursor
   
   Rectangle plant1rec;
   Rectangle plant2rec;
   Rectangle plant3rec;
   Rectangle plant4rec;
   Rectangle plant5rec;
   Rectangle plant6rec;	
   Rectangle plant7rec;
   Rectangle plant8rec;
   Rectangle plant9rec;
   Rectangle backrec;
   Rectangle search2;
   Rectangle nextarr;  ///next arrow
   Rectangle prevarr; ///prev arrow
   
   //----------infoscr   buttons---------//
   Rectangle addx;
   Rectangle obtx;
   Rectangle nextx;
   Rectangle seenx;
   Rectangle backx;
   
   Rectangle cback;
   //-------------------------------------------//
   
      
   //----collection screen rectangles------//
   Rectangle collec_rec;
   Rectangle nextcolrec;
   Rectangle prevcolrec;
   
   
   //----collection screen rectangles------//
   
   
   
   
   //------stack precursor------------------//
    Texture2D stack[100];
    int top=-1;
    int trav;
   //----------------------------------------//
   
   
   //-------------------------------------//
   
   //-----------------------------------------------------------------------------//
   
   
   
   
            //----------width,height,xpos,ypos-----------------//
            srcrect.width=start.width;    //width of rectangle is equal to width of texture start button
            srcrect.height=start.height;   //height of rectangle is equal to height of texture start button
            srcrect.x=startv.x;                      //x position of rectangle is equal to x position of vector of start button
	   srcrect.y=startv.y;                      //y position of rectangle is equal to y position of vector of start button
	   
	   collecrect.width=collec.width;
	   collecrect.height=collec.height;
	   collecrect.x=collecv.x;
	   collecrect.y=collecv.y;
	   
	   
	   searchrect.width=search.width;
	   searchrect.height=search.height;
	   searchrect.x=searchv.x;
	   searchrect.y=searchv.y;
	    //---------------------------------------------------------------------------//
	    
	    
	   //--------------------------loading textures and setting id  ---------------------------------------------------//
          
          medvar medarr[5];
          
          medarr[0].medpic=LoadTexture("./med111.png");
          strcpy(medarr[0].id,"veld grape");
          
          medarr[1].medpic=LoadTexture("./med222.png");
          strcpy(medarr[1].id,"moonseed");
          
          medarr[2].medpic=LoadTexture("./med333.png");
          strcpy(medarr[2].id,"clitoria");
          
          medarr[3].medpic=LoadTexture("./med444.png");
          strcpy(medarr[3].id,"wood sorrel");
          
          medarr[4].medpic=LoadTexture("./med555.png");
          strcpy(medarr[4].id,"curly dock");
          
          //------------------------------------------------------------------------------------------------------------------------------//
          
            int index = -1; // To store the result of the search

    char key[TEMP] = "\00"; // User input for search
    char name[MAX_INPUT_CHARS + 1] = "\00"; // Text input buffer

	   
   
   

    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        

	   

	   
	    mousepos=GetMousePosition();
	   point.width=10;
	   point.height=10;
	   point.x=mousepos.x;
	   point.y=mousepos.y;
	
	   
	  //-------------------------------------------------------------------// 
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        
        
        
        //button sound function//
        
            void clicksound()
             {
               PlaySound(buttonsound);     
               
             }
             
        //--------------------------//
        
        
        
       //image replace function//
       
          void imgreplace(int trav)
            {
             
             temppic[0]=plantpic[trav];
             
           }
           
      //----------------------------------//
      
      // -----------------------Function to search for a texture by its ID-----------------------------------------------------//
int searchTextureByID(medvar medarr[], int count, const char *id) {
    for (int i = 0; i < count; i++) {
        if (strcmp(medarr[i].id, id) == 0) {  // Compare the identifier strings
            return i;  // Return the index of the found texture
        }
    }
    return -1;  // Return -1 if not found
}
   //-------------------------------------------------------------------------------------------------------//
      
      
      
      //info replace function//
      
      
      void inforeplace(int itrav)
      
         {
         
         
            infoscr=LoadTexture("./infoscr1.png");
               tempinfo[0]=LoadTexture("./graytemp.png");
               
               
         //--- infoscreen buttons rec length,width,positon -------//
               
               addx.width=210;
               addx.height=50;
               addx.x=538;
               addx.y=120;
               
               seenx.width=210;
               seenx.height=50;
               seenx.x=538;
               seenx.y=120+60;
               
               
      
          
          //const char *searchID = key;
          
          
          
        
          
               
                 //---------------------keyword store in variable-----------------------------------------------------------------------//
           if (IsKeyDown(KEY_TAB))
              {
               strcpy(key, name);
                collision[55]=true;
                
                searchID = key;
                index = searchTextureByID(medarr, 4, searchID);
               
                
               }
               
               
               if (IsKeyDown(KEY_ENTER))
                   {
                      searchTextureByID(medarr, 5, searchID);
                     }
                   
           //--------------------------------------------------------------------------------------------------------------------//
           
           
              
               
               obtx.width=210;
               obtx.height=50;
               obtx.x=538;
               obtx.y=120+125;
               
               
               nextx.width=210;
               nextx.height=50;
               nextx.x=538;
               nextx.y=obtx.y+65;     
               
               
               
               backx.width=210;
               backx.height=50;
               backx.x=538;
               backx.y=nextx.y+63;       
               
               
               
               //--------collec_scr _back------------------//
               
               cback.width= 132;
               cback.height=46;
               cback.x=650;
               cback.y=  3;         
     
               
              //------------------//
         k=itrav;
         
          tempinfo[0]=infopl[itrav];
         }
      
     
     //-----------------------------//
     
     
     
     //-------stack push------------------//
     
     void push()
       {
       
        if(top==100)
         {
          printf("\n not possible to store data");
         }
        else
          {
         top=top+1;
         stack[top]=tempinfo[0];
          }
      }
      
     //--------------------------------------//    
     
     
     
     //----------stack display--------------------//
    
         void disp(int num)
            {
            
            
               collec_rec.width=0;
               collec_grp.width=0;
               nextcol=LoadTexture("./nextcol.png");
               prevcol=LoadTexture("./prevcol.png");
               nextcolrec.width=nextcol.width;
               nextcolrec.height=nextcol.height;
               prevcolrec.width=prevcol.width;
               prevcolrec.height=prevcol.height;
               nextcolrec.x=700;
               nextcolrec.y=200;
               prevcolrec.x=65;
               prevcolrec.y=200;
            
            
               collec_rec.width=0;
               collec_grp.width=0;
               
                   collecinfo[0]=stack[num];
               

                  
             }
             
     //----------------------------------------------//
         
     
     
     
     
     //----------------vanish --------------------------------------//
     void vanish()
        {
        
        
             
              temppic[0].width=0;
              plant1.width=0;
              plant2.width=0;
              plant3.width=0;
              plant4.width=0;
              plant5.width=0;
              plant6.width=0;
              plant7.width=0;
              plant8.width=0;
              plant9.width=0;
              
              search2.width=0;
                      
               screen2=tempscr;
              //plant1pic=temp;
              temppic[100]=temp;
              backrec.width=0;
               plant1rec.width=0;
              plant2rec.width=0;
              plant3rec.width=0;
              plant4rec.width=0;
              plant5rec.width=0;
              
                  plant6rec.width=0;
              plant7rec.width=0;
              plant8rec.width=0;
              plant9rec.width=0;
              
              
              temppic[0].width=0;
              frame.width=0;
              nextarr.width=0;
              prevarr.width=0;
         }
        
      
        //screen1 element vanisher //
        
        
        
      //----------------infoscrn vanisher-----------------------------//
      
       void vanish2()
          {
          
               addx.width=0;
               seenx.width=0;
               obtx.width=0;
               nextx.width=0;
               backx.width=0;
               infoscr.width=0;
               tempinfo[0].width=0;
               collecrect.width=collec.width;
               srcrect.width=start.width;    //width of rectangle is equal to width of texture start button
               
           
             //  plantpic[0].width=0;
               
          }
          
        //---------------------------------------------------------------------//
        
        
        //-------------------------next button implementation------------------------------------//
        
        
        
        
         collision[12]=CheckCollisionRecs(point,nextx);
         
        if(collision[12])
            {
            
                infosel=LoadTexture("./info_sel.png");
          
                      infoselv.y=nextx.y;
                      infoselv.x=nextx.x;
            
         if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
             
             
             tempinfo[0]=infopl[k];
              k++;
              
              clicksound();
            }
            }
               
        
        
               
     
          
            
        
           
       collision[11]=CheckCollisionRecs(point,plant9rec);
          if(collision[11])
           {
           
             selection=LoadTexture("./selection.png");

            selecv.y=100+315;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
         
              imgreplace(8);
               clicksound();
             }
             
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(8);
                  
                  
                  
                  
              }
             
           }
           
           
           
       //---------------------info and plantpic changer----------------------------------------//
           
        
        void nextrepl()
          {
             infopl[0]=infopl[9];
            infopl[1]=infopl[10];
            infopl[2]=infopl[11];
            infopl[3]=infopl[12];
            infopl[4]=infopl[13];
            infopl[5]=infopl[14];
            infopl[6]=infopl[15];
            infopl[7]=infopl[16];
            infopl[8]=infopl[17];
            infopl[9]=infopl[18];
            
            plantpic[0]=plantpic[9];
            plantpic[1]=plantpic[10];
            plantpic[2]=plantpic[11];
            plantpic[3]=plantpic[12];
            plantpic[4]=plantpic[13];
            plantpic[5]=plantpic[14];
            plantpic[6]=plantpic[15];
            plantpic[7]=plantpic[16];
            plantpic[8]=plantpic[17];
            plantpic[9]=plantpic[18];
                  
            
           }
           
           
       //--------------------------------------------------------------------------------------//
       
       
       void prevrepl()
               {
               
              plant1=LoadTexture("./purslane.png");
             plant2=LoadTexture("./moonseed.png");
             plant3=LoadTexture("./woodsorrel.png");
             plant4=LoadTexture("./turkeyberry.png");
             plant5=LoadTexture("./duckweed.png");
             plant6=LoadTexture("./clitoria.png");
             plant7=LoadTexture("./sowthistle.png");
             plant8=LoadTexture("./veldgrape.png");
             plant9=LoadTexture("./curlydock.png");
             
               infopl[0]=LoadTexture("./1.png");
             infopl[1]=LoadTexture("./2.png");
             infopl[2]=LoadTexture("./3.png");
             infopl[3]=LoadTexture("./4.png");
             infopl[4]=LoadTexture("./5.png");
             infopl[5]=LoadTexture("./6.png");
             infopl[6]=LoadTexture("./7.png");
             infopl[7]=LoadTexture("./8.png");
             infopl[8]=LoadTexture("./9.png");
             infopl[9]=LoadTexture("./10.png");
           
           
              plantpic[0]= LoadTexture("./plant1.png");
             plantpic[1]=LoadTexture("./plant2.png");
             plantpic[2]=LoadTexture("./plant3pic.png");
             plantpic[3]=LoadTexture("./plant4.png");
             plantpic[4]=LoadTexture("./plant5.png");
             plantpic[5]=LoadTexture("./p6.png");
             plantpic[6]=LoadTexture("./plant7pic.png");
             plantpic[7]=LoadTexture("./plant8pic.png");
             plantpic[8]=LoadTexture("./plant9pic.png");
             
           }
       //--------------------------------------------------------------------------------------//
             
        
        
             
        
        
          //---------------------keyword store in variable-----------------------------------------------------------------------//
           if (IsKeyDown(KEY_TAB))
              {
               strcpy(key, name);
                collision[55]=true;
               }
           //------------------------------------------------------------------------------------------------------------------------------------------//
        
        
        
       //-----------draw button----------------//   //ju2
   
          
        
      //--------------------------scr1 start button------------------------------------//  
        collision[0]=CheckCollisionRecs(point,srcrect);
        if(collision[0])
          {
           sc1sel=LoadTexture("./sc1sel.png");
           tempselv=startv;                                                         //jump
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
              //PlaySound(buttonsound);   
              clicksound();           
              srcrect.width=0;
              collecrect.width=0;
              searchrect.width=0;
              DrawText("works!", 190, 200, 20, RED);
              printf("\n it works");
              
             screen2=LoadTexture("./scr2.png");
         
             plant1=LoadTexture("./purslane.png");
             plant2=LoadTexture("./moonseed.png");
             plant3=LoadTexture("./woodsorrel.png");
             plant4=LoadTexture("./turkeyberry.png");
             plant5=LoadTexture("./duckweed.png");
             plant6=LoadTexture("./clitoria.png");
             plant7=LoadTexture("./sowthistle.png");
             plant8=LoadTexture("./veldgrape.png");
             plant9=LoadTexture("./curlydock.png");
             
   
            
            
            
           //-------------plant pictures------------------// 
             plantpic[0]= LoadTexture("./plant1.png");
             plantpic[1]=LoadTexture("./plant2.png");
             plantpic[2]=LoadTexture("./plant3pic.png");
             plantpic[3]=LoadTexture("./plant4.png");
             plantpic[4]=LoadTexture("./plant5.png");
             plantpic[5]=LoadTexture("./p6.png");
             plantpic[6]=LoadTexture("./plant7pic.png");
             plantpic[7]=LoadTexture("./plant8pic.png");
             plantpic[8]=LoadTexture("./plant9pic.png");
             
             plantpic[9]=LoadTexture("./10pi.png");
             plantpic[10]=LoadTexture("./plant11pic.png");
             plantpic[11]=LoadTexture("./plant12pic.png");
             plantpic[12]=LoadTexture("./plant13pic.png");
             plantpic[13]=LoadTexture("./plant14pic.png");
             plantpic[14]=LoadTexture("./plant15pic.png");
             plantpic[15]=LoadTexture("./plant16pic.png");
             plantpic[16]=LoadTexture("./plant17pic.png");
             plantpic[17]=LoadTexture("./plant18pic.png");
                 
              //-----------------------------------------------------------------------//
              
              
             
             
             
             

             
             
             frame=LoadTexture("./frame.png");
           //----------------------------------------------//
           
           
           
           
           
          //------plant info strips----------------------------------------------------------//   
             
            //--------------batch1------------------------//
             infopl[0]=LoadTexture("./1.png");
             infopl[1]=LoadTexture("./2.png");
             infopl[2]=LoadTexture("./3.png");
             infopl[3]=LoadTexture("./4.png");
             infopl[4]=LoadTexture("./5.png");
             infopl[5]=LoadTexture("./6.png");
             infopl[6]=LoadTexture("./7.png");
             infopl[7]=LoadTexture("./8.png");
             infopl[8]=LoadTexture("./9.png");
             infopl[9]=LoadTexture("./10.png");
            //--------------------------------------------------//
            
            
            //-----------batch 2-------------------------------//
            
             infopl[10]=LoadTexture("./11.png");
             infopl[11]=LoadTexture("./12.png");
             infopl[12]=LoadTexture("./13.png");
             infopl[13]=LoadTexture("./14.png");
             infopl[14]=LoadTexture("./15.png");
             infopl[15]=LoadTexture("./16.png");
             infopl[16]=LoadTexture("./17.png");
             infopl[17]=LoadTexture("./18.png");
             infopl[18]=LoadTexture("./19.png");
             infopl[19]=LoadTexture("./20.png");
             
            //------------------------------------------------------//
                
             
         //-------------------------------------------------------------------------------------//
             
             
             plant1rec.width=plant1.width;
             plant1rec.height=plant1.height;
             plant1rec.x=290;
             plant1rec.y=55;
             
             
            plant2rec.width=plant2.width;
	   plant2rec.height=plant2.height;
	   plant2rec.x=290;
	   plant2rec.y=100;
	   
	   
	    plant3rec.width=plant3.width;
	   plant3rec.height=plant3.height;
	   plant3rec.x=290;
	   plant3rec.y=145;
	   
	   
	    plant4rec.width=plant4.width;
	   plant4rec.height=plant4.height;
	   plant4rec.x=290;
	   plant4rec.y=190;
	   
	   
	    plant5rec.width=plant5.width;
	   plant5rec.height=plant5.height;
	   plant5rec.x=290;
	   plant5rec.y=235;
	   
	   
	   
	    plant6rec.width=plant6.width;
	   plant6rec.height=plant6.height;
	   plant6rec.x=290;
	   plant6rec.y=280;


            
	    plant7rec.width=plant7.width;
	   plant7rec.height=plant7.height;
	   plant7rec.x=290;
	   plant7rec.y=325;	   
	   
	   
	   
	    plant8rec.width=plant8.width;
	   plant8rec.height=plant8.height;
	   plant8rec.x=290;
	   plant8rec.y=370;
	   
	   
	   
	    plant9rec.width=plant9.width;
	   plant9rec.height=plant9.height;
	   plant9rec.x=290;
	   plant9rec.y=415;
	   
	   
	   
	   
	   backrec.width=145;
	   backrec.height= 60;
	   backrec.x=600;
	   backrec.y=230;
	   
	   
	   search2.width=145;
	   search2.height=60;
	   search2.x=600;
	   search2.y=backrec.y-72;
	   
	   
	   nextarr.width=20;
	   nextarr.height=40;
	   nextarr.x=570;
	   nextarr.y=415;
	   
	   
	   prevarr.width=20;
	   prevarr.height=40;
	   prevarr.x=570;
	   prevarr.y=55;
	   
              
          
               }
          }
          
      //------------------------------------------------------------------------------//    
          
          
          
      //------------------------------collection button-------------------------------//
                  collision[1]=CheckCollisionRecs(point,collecrect);
        if(collision[1])
          {
           sc1sel=LoadTexture("./sc1sel.png");  //overlay
           tempselv=collecv;  
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
                   collision[13]=true;
                    clicksound();  
              
              srcrect.width=0;    //remove rect 
              collecrect.width=0;  //remove collecrect
              searchrect.width=0;   //remove searchrect
              DrawText("works!", 190, 200, 20, RED);
              printf("\n it works");
              
              collec_scr=LoadTexture("./collec.png");
              back_collec=LoadTexture("./backv2.png");
              
                  
              collec_grp=LoadTexture("./col1.png");
              collec_rec.width=collec_grp.width;
              collec_rec.height=collec_grp.height;
              collec_rec.x=20;
              collec_rec.y=50;
              
              
          
               }
          }
       //--------------------------------------------------------------------------------//
       
       
       
       
       
       
       //-----------------------------search ------------------------------------------//
          
          
                  collision[2]=CheckCollisionRecs(point,searchrect);
        if(collision[2])
          {
              sc1sel=LoadTexture("./sc1sel.png");
           tempselv=searchv; 
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {    
                    clicksound();
              
              srcrect.width=0;
              collecrect.width=0;
              searchrect.width=0;
              DrawText("works!", 190, 200, 20, RED);
              printf("\n it works");
              
              search_back=LoadTexture("./backv2.png");
              
              
              
          
               }
          }
          
          
          
      //------------------------search end-----------------------------------------------//
      
      
      
      //------------------------------------------buttons-----------------------------------------------------------------//
      
      
     // int trav=0;
      
    //  for(trav=3;trav<30;trav++)
      //   {
         
         
         
         collision[51]=CheckCollisionRecs(point,plant1rec);
        if(collision[51])
            {
              selection=LoadTexture("./selection.png");
              selecv.x=290;
             
              
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
               
               imgreplace(0);  //purslane
               clicksound();
             }
           
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
               {
                 inforeplace(0);
                 vanish();
                }
                
                }
               
          
          collision[3]=CheckCollisionRecs(point,plant2rec);
          if(collision[3])
           {
            selection=LoadTexture("./selection.png");
            selecv.x=290;
            selecv.y=100;
            
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
            imgreplace(1);   //replacing moonseed image
              clicksound();
             }
             
             
            if(  IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
              {
              
              infoscr=LoadTexture("./infoscr1.png");
               tempinfo[0]=LoadTexture("./graytemp.png");
              
              inforeplace(1);
              vanish();
              
              }	
           }
           
           
           else
              {
                selection=LoadTexture("./blankplant.png");
           }
           
           

      
      
      
     
                   collision[4]=CheckCollisionRecs(point,plant3rec);
          if(collision[4])
           {
                selection=LoadTexture("./selection.png");
             
                selecv.y=100+45;
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {

            
            imgreplace(2) ; //woodsorrel replace
              clicksound();
             
             }
             
             
             
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
           
             {
             
             
             vanish();
             inforeplace(2);
             buto=1;
              

          }
           }	
                      
          
           
           
                          collision[5]=CheckCollisionRecs(point,plant4rec);
          if(collision[5])
           {
           
             selection=LoadTexture("./selection.png");
            selecv.y=100+90;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
               PlaySound(buttonsound);      
              imgreplace(3);  //turkey berry
               clicksound();
             }
             
           
           
           
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(3);
                  
                  
              }
              
          }
                  
                 


                   
           
        
           
           
                             collision[16]=CheckCollisionRecs(point,plant6rec);
          if(collision[16])
           {
           
             selection=LoadTexture("./selection.png");
           // selecv.x=290;
            selecv.y=100+180;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
             imgreplace(5);
              clicksound();
             }
             
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(5);
                  
                  
              }
             
           }	
           
                               collision[9]=CheckCollisionRecs(point,plant7rec);
          if(collision[9])
           {
           
             selection=LoadTexture("./selection.png");
           // selecv.x=290;
            selecv.y=100+225;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
              imgreplace(6);   
               clicksound();
             }
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(6);
                  
                  
              }
             
           }
           
           
           
                               collision[10]=CheckCollisionRecs(point,plant8rec);
          if(collision[10])
           {
           
             selection=LoadTexture("./selection.png");
           // selecv.x=290;
            selecv.y=100+270;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
               imgreplace(7);
               clicksound();
             }
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(7);
                  
                  
              }
             
             
           }
           
           
                               collision[11]=CheckCollisionRecs(point,plant9rec);
          if(collision[11])
           {
           
             selection=LoadTexture("./selection.png");
           // selecv.x=290;
            selecv.y=100+315;
            
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
              imgreplace(8);
               clicksound();
             }
             
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(8);
                  
                  
              }
             
           }
           
           
              
  
           
           
          
          
           
           
           
      
           
           
           
           
                               collision[6]=CheckCollisionRecs(point,plant5rec);
          if(collision[6])
           {
          
              selection=LoadTexture("./selection.png");
            selecv.y=100+135;
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
              
             imgreplace(4);
              clicksound();
             }
             
             
             
                
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(4);
                  
                  
              }
             
           }
           
       
          
           
           
       //--------------------------------------------buttons----------------------------------------------------------------//
       
       
       
       //----------------------------------------next arrow -------------------------------------------------------------------//
       
      
        
       collision[25]=CheckCollisionRecs(point,nextarr);
       
       if(collision[25])
          {
             if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
                  printf("stupid stupid  stupid");
                  clicksound();
               //---replace buttons------//   
                  plant1=buttonx[0];
                  plant2=buttonx[1];
                  plant3=buttonx[2];
                  plant4=buttonx[3];
                  plant5=buttonx[4];
                  plant6=buttonx[5];
                  plant7=buttonx[6];
                  plant8=buttonx[7];
                  plant9=buttonx[8];
               //--------------------------------//  

               
               
                  
               }
               
               
               
             //---------------replace info-------------------//
              nextrepl();
              
         }
       
       
                 collision[53]=CheckCollisionRecs(point,prevarr);
       
       if(collision[53])
          {
             if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
                  printf("return");
                  clicksound();
                  prevrepl();
               }
               
               
               
             //---------------replace info-------------------//

         }
       
       
       
       
       
       //----------------------------------------------------------------------------------------------------------------------//
       
       
      //-----------------------------------------scr2 back button------------------------------------------------------------//	
           
           
          collision[7]=CheckCollisionRecs(point,backrec);
          if(collision[7])
           {
           
             bigsel=LoadTexture("./bigsel.png");
             bigselv.x=backrec.x-2;
             bigselv.y=backrec.y-2;
          
           if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
            
                  // PlaySound(buttonsound);     
                  clicksound(); 
              
              screen2=tempscr;
             srcrect.width=start.width;
            collecrect.width=collec.width;
             searchrect.width=search.width;

              
              vanish();
             
             }
             
           }	
           
               else
              {
                bigsel=LoadTexture("./blankplant.png");
                bigselv.x=search2.x-2;
                bigselv.y=search2.y-2;
           }
           
           
           //----------------------------------------------------scr2 backbutton----------------------------------------------------------------------------------------//
           
           
           //
           
           collision[8]=CheckCollisionRecs(point,search2);
           
           if(collision[8])
              {
                 bigsel=LoadTexture("./bigsel.png");
                 
                
               if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                   {
                   
                      searchscreen=LoadTexture("./searchres.png");
                      
              plant1.width=0;
              plant2.width=0;
              plant3.width=0;
              plant4.width=0;
              plant5.width=0;
              plant6.width=0;
              plant7.width=0;
              plant8.width=0;
              plant9.width=0;
              
              search2.width=0;
                      
               screen2=tempscr;
              //plant1pic=temp;
              temppic[100]=temp;
              backrec.width=0;
              plant2rec.width=0;
              plant3rec.width=0;
              plant4rec.width=0;
              plant5rec.width=0;
              
                  plant6rec.width=0;
              plant7rec.width=0;
              plant8rec.width=0;
              plant9rec.width=0;
            
                   
                    }
                    
              }
                
           
             //--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
             
             
             
             //-------------infoscreen buttons implementaion-----------------------------------------//
             
             collision[30]=CheckCollisionRecs(point,addx);
             
               if(collision[30])
                 {
                 
                      infosel=LoadTexture("./info_sel.png");
          
                      infoselv.y=addx.y;
                      infoselv.x=addx.x;
                 
                 
                 
                 if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                   push();
                     clicksound();
                    }
                   
                 }
                 
                 
              collision[32]=CheckCollisionRecs(point,backx);
              
                 if(collision[32])
                    {
                        infosel=LoadTexture("./info_sel.png");
          
                      infoselv.y=backx.y;
                      infoselv.x=backx.x;
                    
                    
                     // 
                      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        {
                        
                          infosel=LoadTexture("./blankplant.png");
                          searchrect.width=search.width;
                        
                        clicksound();
                        vanish2();
                         
                        }
                      }
     
          
           //----------------------------infoscreen end implementation-------------------------------------//
           
           
           
           
           
           
           
           //------------------collection screen interaction implementation-----------------//
           
           collision[31]=CheckCollisionRecs(point,collec_rec);
           
           if(collision[31])
             {
               if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                   disp(top);
                 }
                 
              }
              
          //-------------------------------------------------------------------------------------//
          
              //----------------next button (travese through stack)---------//
              
              collision[32]=CheckCollisionRecs(point,nextcolrec);
              
                if(collision[32])
                  {
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                       {
                       
                       int num=top;
                        top--;
                         disp(num);
                       }
                       
                  }
                  
             //-------------------------------------------------------------//     
                  
                collision[33]=CheckCollisionRecs(point,prevcolrec);
                 if(collision[33])
                   {
                     if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                       {
                        int rnum=top;
                          top++;
                          disp(rnum);
                        }
                      }
                     
          //-------------------------------------------------------------------------------------//
           
           
           
           //-------------------collection screen  back-----------------------------------//
         void vanish3()
              {
              
              prevcol.width=0;
              nextcol.width=0;
              cback.width=0;
              back_collec.width=0;
              collec_scr.width=0;
              tempinfo[0].width=0;
              stack[10]=LoadTexture("./blankplant.png");
              collecinfo[0].width=0;
                     srcrect.width=start.width;
            collecrect.width=collec.width;
             searchrect.width=search.width;
              
              }             
           
           
         //----------------------------impli---------------------------------//
         
         collision[14]=CheckCollisionRecs(point,cback);
         
         if(collision[14])
            {
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
               {
              vanish3();
              cback.width=0;
             }
           }
             
        //---------------------------------------------------------------------//
        
        
        
        // ------search vanish------------------//
        
        void vanish4()
           {
              collec_scr.width=0;
              tempmed.width=0;
          }
          
       //---------------------------------------------//
   
           
           
           
           //------------------collection screen impli end ----------------------------------//
           

         // --------------------------------------input box-------------------------------------------------------//
    if (CheckCollisionPointRec(GetMousePosition(), textBox))
      mouseOnText = true;
    else
      mouseOnText = false;

    if (mouseOnText)
    {
      // Set the window's cursor to the I-Beam
      SetMouseCursor(MOUSE_CURSOR_IBEAM);

      // Get char pressed (unicode character) on the queue
      int key = GetCharPressed();

      // Check if more characters have been pressed on the same frame
      while (key > 0)
      {
        // NOTE: Only allow keys in range [32..125]
        if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
        {
          name[letterCount] = (char)key;
          name[letterCount + 1] = '\0'; // Add null terminator at the end of the string.
          letterCount++;
        }

        key = GetCharPressed(); // Check next character in the queue
      }

      if (IsKeyPressed(KEY_BACKSPACE))
      {
        letterCount--;
        if (letterCount < 0)
          letterCount = 0;
        name[letterCount] = '\0';
      }
    }
    else
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);


    //--------------------------------------------- inputbox-----------------------------------------------------------------------------------------//

          
          
        BeginDrawing();

            ClearBackground(RAYWHITE);
            


            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawTexture(logo,5,5,WHITE);      //draws logo texture on screen
            DrawTextureV(start,startv,WHITE);    //draws start buton
            DrawTextureV(collec,collecv,WHITE);   //draws collections button
            DrawTextureV(search,searchv,WHITE);   //draws search button
            DrawTextureV(sc1sel,tempselv,WHITE);  //--------------------------------------------- //selection overlay//
            DrawTexture(screen2,5,5,WHITE);       //main scr
            DrawTexture(collec_scr,5,0.5,WHITE);   //collection screen
            DrawTexture(back_collec,650,3,WHITE);
            DrawTexture(search_back,650,410,WHITE);
            DrawTexture(tempmed,80,160,WHITE);  //tempmed
            DrawTexture(collec_grp,20,50,WHITE);   //collection group image
            DrawTexture(collecinfo[0],150,40,WHITE);  //display info in stack
            DrawTexture(nextcol,700,200,WHITE);   //next button in collection screen
            DrawTexture(prevcol,65,200,WHITE);    //previous button in collection screen
            DrawTexture(plant1,290,55,WHITE);	
            DrawTexture(plant2,290,100,WHITE);
            DrawTexture(plant3,290,145,WHITE);
            DrawTexture(plant4,290,190,WHITE);
            DrawTexture(plant5,290,235,WHITE);
            DrawTexture(plant6,290,280,WHITE);
            DrawTexture(plant7,290,325,WHITE);
            DrawTexture(plant8,290,370,WHITE);
            DrawTexture(plant9,290,415,WHITE);
          
          
            DrawRectangleLinesEx(prevarr,2.0,GREEN);
            DrawRectangleLinesEx(nextarr,2.0,GREEN); //rect on arrow 
            DrawTexture(temppic[0],40,72,WHITE); 
            DrawTexture(frame,25,320,WHITE);
            DrawTextureV(selection,selecv,WHITE);  //draw overlay
            
        
            DrawTextureV(bigsel,bigselv,WHITE);   //backrec.x-5,backrec.y-3
          
            DrawRectangleLinesEx(srcrect,2.0,RED);   //draws rectangle on start
            DrawRectangleLinesEx(collecrect,2.0,RED);  //draws rectangle on collect
            DrawRectangleLinesEx(searchrect,2.0,RED);   //draws rectangle on searchbutton
          
            DrawRectangleRec(point,BLUE);
            DrawTexture(searchscreen,5,5,WHITE);
            DrawTexture(infoscr,5,5,WHITE);
            DrawTexture(tempinfo[0],5,37,WHITE);
        
            
            
            
            
            //---------draw rect on buttons-------------------//
             DrawRectangleLinesEx(plant1rec,2.0,GREEN);
            DrawRectangleLinesEx(plant2rec,2.0,GREEN);  
            DrawRectangleLinesEx(plant3rec,2.0,GREEN);
            DrawRectangleLinesEx(plant4rec,2.0,GREEN);
            DrawRectangleLinesEx(plant5rec,2.0,GREEN);
            
            DrawRectangleLinesEx(plant6rec,2.0,GREEN);
            DrawRectangleLinesEx(plant7rec,2.0,GREEN);
            DrawRectangleLinesEx(plant8rec,2.0,GREEN);
            DrawRectangleLinesEx(plant9rec,2.0,GREEN);
            
            DrawRectangleLinesEx(backrec,2.0,ORANGE);
            DrawRectangleLinesEx(search2,2.0,GREEN);
            
            if(collision[13])
               {
                    DrawRectangleLinesEx(cback,2.0,GREEN);
                }
            
             if(collision[2])
	       {
	       
	    
	   if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	        {
	        
	         collision[56]=true;
	         clicksound();
	          srcrect.width=0;
                  collecrect.width=0;
                  searchrect.width=0;
                  DrawText("works!", 190, 200, 20, RED);
                  printf("\n it works");
                  logo.width=0;
                  collec.width=0;
                  start.width=0;
                  search.width=0;
             // selec.width=0;
                  sc1sel.width=0;
                  collec_scr=LoadTexture("./collec.png");
                  tempmed=LoadTexture("./blankplant.png");
	        }
	       }
	        
	        
	         
	   if(collision[56])
	     { 
            
            
             // -------------------------------input box-----------------------------------------------------------------------------------------------------------//
    // DrawText("Enter your name", 280, 140, 30, GREEN);
    DrawRectangleRec(dumbox, BLANK);
    DrawRectangleRec(textBox, LIGHTGRAY);
    if (mouseOnText)
      DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width+10, (int)textBox.height, RED);
    else
      DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width+10, (int)textBox.height, DARKGRAY);

    DrawText(name, (int)dumbox.x + 10, (int)dumbox.y + 2, 45, BLUE);

    //DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, GREEN);

    if (mouseOnText)
    {
      if (letterCount < MAX_INPUT_CHARS)
      {
        // Draw blinking underscore char
        if (((framecounter / 20) % 2) == 0)
          DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
      }
      else
        DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
    }
    
    }
    // --------------------------------------------input box------------------------------------------------------------------------------------------------//
    
        framecounter++;
           if(collision[55])
                   {
                    DrawText(key,100,200,20,GREEN);
                   }
                   
    // Handle TAB key press for triggering search
        if (IsKeyDown(KEY_TAB))
        {
            strcpy(key, name);            // Copy entered text to key
            index = searchTextureByID(medarr, 5, key); // Perform search
        }

        // Display input text field
        DrawText("Enter plant name and press TAB to search:", 10, 10, 20, DARKGRAY);
        DrawText(name, 10, 40, 20, DARKGREEN); // Display the entered name

        // Handle text input
        int keyPressed = GetKeyPressed();
        if ((keyPressed >= 32) && (keyPressed <= 125) && (strlen(name) < MAX_INPUT_CHARS))
        {
            int len = strlen(name);
            name[len] = (char)keyPressed;
            name[len + 1] = '\00';
        }
        if (IsKeyPressed(KEY_BACKSPACE) && strlen(name) > 0)
        {
            name[strlen(name) - 1] = '\00';
        }

        // Draw search result: texture or error message
        if (index != -1)
        {
            DrawText(TextFormat("Found texture: %s at index %d", key, index), 10, 120, 20, DARKGREEN);
           tempmed=medarr[index].medpic;// Draw the found texture
        }
        else if (strlen(name) > 0)
        {
            DrawText("Texture not found!", 10, 80, 20, RED); // Show error if not found
        }
        
        
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    
            DrawRectangleLinesEx(addx,2.0,GREEN);   //second screen add button
            DrawRectangleLinesEx(seenx,2.0,GREEN);  //second screen seen button
            DrawRectangleLinesEx(obtx,2.0,GREEN);   //second screen obtained button
            DrawRectangleLinesEx(nextx,2.0,GREEN);  //second screen next button
            DrawRectangleLinesEx(backx,2.0,GREEN);  //second screen back button
            
            
            if(collision[32])
               {
                DrawTextureV(infosel,infoselv,WHITE);
               }
            
           
	    //-----------------------------------------------//
	    
	    
	    
	    //------draw texture w.r.t collection screen----------------//
	    
	   
	    
	    
	    //---------draw rect w.r.t collection screen----------------//
	    DrawRectangleLinesEx(collec_rec,2.0,GREEN);
	    
	    
	
	  
        EndDrawing(); 
           }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}









