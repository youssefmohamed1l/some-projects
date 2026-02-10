let menu = document.getElementById("menu")
let action = document.getElementById("action")

menu.onclick = function(){
    //لما اضغط علي المنيو خليلي الاكشن هالو
    //لما اضغط علي المنيو خليلي المنيو هالو

    action.classList.toggle("helo");
    menu.classList.toggle("helo");
}