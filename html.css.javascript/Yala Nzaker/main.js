let menu = document.getElementById("menu")
let action = document.getElementById("action")

menu.onclick = function(){
    //لما اضغط علي المنيو خليلي الاكشن هالو
    //لما اضغط علي المنيو خليلي المنيو هالو

    action.classList.toggle("content-menu");
    menu.classList.toggle("content-menu");
}