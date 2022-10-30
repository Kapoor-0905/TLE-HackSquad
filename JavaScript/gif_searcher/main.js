
// txt.addEventListener('input',()=>{
//     console.log(txt.value);
// })
let txt = document.querySelector("input");

document.querySelector('.search').addEventListener('click', () => {
    clearDom();
    entered(txt.value);

});
document.querySelector('#search').addEventListener('keyup', (e) => {

    if (e.which === 13) {
        clearDom();
        entered(txt.value);
    }
});

//processing api
let entered = (e)=>{
   e=e.replaceAll(' ','+');

   let APIkey = 'NhMBkHxGigLnmA4bqrgllJMwoN6O6PQx';
   
   let url = `https://api.giphy.com/v1/gifs/search?api_key=${APIkey}&q=${e}`;
   let GiphyAJAXCall = new XMLHttpRequest();
   GiphyAJAXCall.open('GET',url);
   GiphyAJAXCall.send();
   
   GiphyAJAXCall.addEventListener('load', (e)=>{
       let data = e.target.response;
       pushToDOM(data);       
    })
}
    

// showing the results images.fixed_height.url

let box = document.querySelector(".box");
let pushToDOM = (input) => {

    let response = JSON.parse(input);
    
    let imgres = response.data;
    imgres.forEach(i=> {
        let rr= i.images.fixed_height.url;
         
        box.innerHTML += `<img src='${rr}'>`; 
    });
}


let clearDom = ()=>{
    box.innerHTML="";
}

