score=0;
cross=0;
backMusic = new Audio('2019-10-30_-_Action_Rhythms_-_David_Fesliyan.mp3');
laugh = new Audio ('Children_Laughing-Mike_Koenig-575083331-[AudioTrimmer.com].mp3');
roar = new Audio ('Tyrannosaurus Rex-SoundBible.com-2136096676 (1).mp3');
   backMusic.play();
document.addEventListener("keydown", function f( e){
    let dino = document.querySelector(".dino");
    console.log(e.keyCode);
    if (e.keyCode==38 || e.keyCode==32){
        dino.classList.add("jumpDino");
        setTimeout(() => {
            dino.classList.remove("jumpDino");
        }, 600);
    }
    else if(e.keyCode==39) 
     { let dinoX =  parseInt(window.getComputedStyle(dino,null).getPropertyValue('left') );
      dino.style.left = dinoX+150+"px";
}
    else if(e.keyCode==37) 
     { let dinoX =  parseInt(window.getComputedStyle(dino,null).getPropertyValue('left') );
      dino.style.left = (dinoX-150)+"px";
}
    
   
    else{
        
    }
});
setInterval(() => {
    let dino = document.querySelector(".dino");
    let obstacle=document.querySelector(".obstacle");
    let gameOver=document.querySelector(".gameOver")
    let dx= parseInt(window.getComputedStyle(dino,null).getPropertyValue('left') );   
    let dy= parseInt(window.getComputedStyle(dino,null).getPropertyValue('bottom') );   
    let ox= parseInt(window.getComputedStyle(obstacle,null).getPropertyValue('left') );   
    let oy= parseInt(window.getComputedStyle(obstacle,null).getPropertyValue('bottom') );
    let distX = Math.abs(ox-dx);
    let distY = Math.abs(dy-oy);
   
   if (distX < 90 && distY< 50 ){ 
       gameOver.style.visibility="visible";
       obstacle.classList.remove("animateObstacle");
       
  }
else{
   if ( dx>ox) 
    {setScore(cross);}
   else{
       cross=0;
   }
}
 if (ox==0){
    let animDur = parseFloat(window.getComputedStyle(obstacle,null).getPropertyValue('animation-duration') );
    animDur -= 0.1;
    obstacle.style.animationDuration = animDur +'s';
    roar.play();
 }
}, 10);

function setScore(element){
    let scoreCount= document.getElementById("scoreCount");
    
    if(element==0)
    {scoreCount.innerHTML = "Score:"+ (score+=50);
     laugh.play();
}
    
    
    cross=1;
}
