let content_right = document.querySelector('.content-right')
let ul = document.querySelector(".ul")
let box = document.querySelector('.box')

function getPost(id) {
    let request = new XMLHttpRequest();
    request.open("GET", "https://jsonplaceholder.typicode.com/posts?userId=" + id)
    request.responseType = "json"
    request.send();
    request.onload = function () {
        if (request.status >= 200 && request.status < 300) {
            posts = request.response;
            box.innerHTML = "";
            for (post of posts) {
                box.innerHTML += `
                    <div class="post">
                        <h4>${post.title}</h4>
                        <hr class="my-2">
                        <h5>${post.body}</h5>
                    </div>
                `
            }
        } else {
            alert("Error")
        }
    }
}

function get_users(id) {
    let request = new XMLHttpRequest();
    request.open("GET", "https://jsonplaceholder.typicode.com/users")
    request.responseType = 'json'
    request.send();
    request.onload = function () {
        ul.innerHTML = "";
        if (request.status >= 200 && request.status < 300) {
            let users = request.response;
            for (user of users) {
                ul.innerHTML += `
                <li class="li ${user.id == 1 ? 'active' : ''}"  onclick="action(${user.id}, this)">
                    <h4>${user.name}</h4>
                 <h6>${user.email}</h6>
                </li>
            `
            }
        } else {
            alert("error");
        }
    }
}

function action(id, el) {
    getPost(id)
    let ALL_li = document.querySelectorAll(".li")

    let elements = document.getElementsByClassName('active')
    for (ele of elements) {
        ele.classList.remove('active')
    }

    el.classList.add('active');
}

get_users();
getPost(1)