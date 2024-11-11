//------------important code and functions--------------------//



      
       //----image replace function-----//                                     
                                                                   
          void imgreplace(int trav)
            {
             
             temppic[0]=plantpic[trav];
             
           }
           
      //----------------------------------//
      
      
      
      
      //----inforeplace function------//
      
         void inforeplace(int itrav)
      
         {
            infoscr=LoadTexture("./infoscr1.png");
            tempinfo[0]=LoadTexture("./graytemp.png");
            tempinfo[0]=infopl[itrav];
         }
      
      //--------------------------------------//
      
      
      
      
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
     
     
     
     
     //--------------next arrow implementation / nextrepl function call----------------------//
     
     
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
               //----------------------//  

               
               
                  
               }
               
               
               
             //---------------replace info-------------------//
              nextrepl();
              
         }
       //------------------------------------------------------------------------------------------------------------------------------//
     
     
     
     
     
     
     
     
     
     
     //------stack display---------------//
     
     
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
               collecinfo[0]=stack[num];
  
                  
             }
             
             
     //-------------------------------------//
     
     
    //------vanish()-------------------------//
     
      void vanish()
        {
        
        
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
              
              
              temppic[0].width=0;
              frame.width=0;
         }
         
         
         //------------------------------------------//
         
         
     //----vanish2---------------------//
         
         
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
               nextarr.width=0;
             //  plantpic[0].width=0;
               
          }
               
    //--------------------------------//
    
    
    
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
             
        
        
        
        //-------replace image call example----------//
        
        collision[3]=CheckCollisionRecs(point,plant2rec);
          if(collision[3])
           {
            selection=LoadTexture("./selection.png");
            selecv.x=290;
            selecv.y=100;
            
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            {
         
            imgreplace(1);   //replacing moonseed image
              clicksound();
             }
         //------------------------------------//
         
         
         
         //----------info replace call example  && vanish function call example -----//
         
                 
           if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            
              {
                  vanish();
                  inforeplace(3);
                  
                  
              }
              
          }
                  
             
         //--------------------------------//
    
    
    
    
    //----add button stack push function call -----------//
    
        collision[30]=CheckCollisionRecs(point,addx);
             
               if(collision[30])
                 {
                 
                 // clicksound();
                 
                 if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                   push();
                    }
                   
                 }
                 
                 
    //----------------------------------------------------//
    
    
    
    
    //--------------back button /vanish2 function call example---------//
    
              
              collision[32]=CheckCollisionRecs(point,backx);
              
                 if(collision[32])
                    {
                    
                     // clicksound();
                      if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                        {
                        vanish2();
                         
                        }
                      }
    //--------------------------------------------------------------------//
    
    
    
    
    //------------------stack display example-------------------------//
        collision[31]=CheckCollisionRecs(point,collec_rec);
           
           if(collision[31])
             {
               if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                   disp(top);
                 }
                 
              }
              
    //-------------------------------------------------------------------//
    
    
    
    //-----------------stack traversal--------------------------------//
    
       //----------------next button (travese through stack---------//
              
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
                  
                  
       //-------------------------------------------------------------//     
   
       
    
    
    
    
    
    
     
    
        
