let stars1 = document.getElementById('stars1')
let moon2 = document.getElementById('moon2')
let mountains3 = document.getElementById('mountains3')
let mountains4 = document.getElementById('mountains4')
let river5 = document.getElementById('river5')
let boat6 = document.getElementById('boat6')
let mountains7 = document.getElementById('mountains7')
let nouvil = document.querySelector('.nouvil')

onscroll = function(){
    let value = scrollY;
    stars1.style.left = value + 'px';
    moon2.style.top = value*3 + 'px';
    mountains3.style.top = value*1.5 + 'px';
    mountains4.style.top = value*1.2 + 'px';
    river5.style.top = value*.5 + 'px';
    boat6.style.top = value*.5 + 'px';
    boat6.style.left = value*3 + 'px';
    nouvil.style.fontSize = value + 'px';
    if(scrollY >= 70){
        nouvil.style.fontSize = 70 + 'px';
    }
}
console.log('hello')