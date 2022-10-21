let txt = document.querySelector("input");

document.querySelector('.btn').addEventListener('click', () => {
    // clearDom();
    entered(txt.value);

});
document.querySelector('#search-input').addEventListener('keyup', (e) => {

    if (e.which === 13) {
        // clearDom();
        entered(txt.value);
    }
});

let entered=(e)=>{
    e=e.replaceAll(' ','+');
    let url = `https://api.dictionaryapi.dev/api/v2/entries/en/${e}`;
    let response = fetch(url)
        .then(response=>response.text())
        .then((data)=>{
           getData(data);
        })
}

let getData = (data)=>{
    let res = JSON.parse(data)
    let arr = res[0].meanings;
    let word = document.getElementById('word');
    
    let addElement = document.getElementsByClassName('addElement')[0];
    word.innerHTML="<h2>"+res[0].word+"</h2>";
    // pos.innerHTML= res[0].meanings[0].partOfSpeech;
    
    for (const key in arr) {
        let pos = document.createElement("span");
        pos.className="pos";
        pos.innerHTML="Part Of Speech: "+ "<h3>"+arr[key].partOfSpeech+"</h3>";
        addElement.appendChild(pos);
        
        let ele = document.createElement("span");
        ele.className="pos";
        ele.innerHTML= "Definition: "+"<h3>"+arr[key].definitions[0].definition+"</h3>";
        addElement.appendChild(ele);

    }  
}
