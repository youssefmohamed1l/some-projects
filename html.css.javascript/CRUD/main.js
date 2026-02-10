let title = document.getElementById('title');
let price = document.getElementById('price');
let taxes = document.getElementById('taxes');
let ads = document.getElementById('ads');
let discount = document.getElementById('discount');
let total = document.getElementById('total');
let count = document.getElementById('count');
let category = document.getElementById('category');
let submit = document.getElementById('submit')
let tbody = document.getElementById('tbody')

let mood = 'create';
let tmp;
function gettotal() {
    if (price.value != '') {
        let result = (+price.value + +taxes.value + +ads.value) - +discount.value;
        total.innerHTML = result;
        total.style.background = 'green';
    }
    else {
        total.style.background = 'rgb(133, 7, 7)';
        total.innerHTML = '';
    }
}

let storageProduct;

if (localStorage.product != null) {
    storageProduct = JSON.parse(localStorage.product);
} else {
    storageProduct = [];
}

showdata();

submit.onclick = function () {
    let newProduct = {
        title: title.value.toLowerCase(),
        price: price.value,
        taxes: taxes.value,
        ads: ads.value,
        discount: discount.value,
        total: total.innerHTML,
        count: count.value,
        category: category.value.toLowerCase(),
    }

    if (title.value != '' && price.value != '' && category.value != '' && count.value < 100) {
        if (mood == 'create') {
            if (newProduct.count > 1) {
                for (let i = 0; i < newProduct.count; i++) {
                    storageProduct.push(newProduct);
                }
            } else {
                storageProduct.push(newProduct);
            }
        } else {
            storageProduct[tmp] = newProduct;
            submit.innerHTML = 'Create';
            count.style.display = 'block';
            mood = 'create';
        }
        cleardata();
    }

    localStorage.setItem('product', JSON.stringify(storageProduct))
    showdata()
}

function cleardata() {
    title.value = '';
    price.value = '';
    taxes.value = '';
    ads.value = '';
    discount.value = '';
    total.innerHTML = '';
    count.value = '';
    category.value = '';
    total.style.backgroundColor = 'rgb(133, 7, 7)'
}

function showdata() {
    let table = '';
    for (let i = 0; i < storageProduct.length; i++) {
        table += `
        <tr> 
            <td>${i + 1}</td>
            <td>${storageProduct[i].title}</td>
            <td>${storageProduct[i].price}</td>
            <td>${storageProduct[i].taxes}</td>
            <td>${storageProduct[i].ads}</td>
            <td>${storageProduct[i].discount}</td>
            <td>${storageProduct[i].total}</td>
            <td>${storageProduct[i].category}</td>
            <td><button onclick="updatedata(${i})" id="update">update</button></td>
            <td><button onclick="deletedata(${i})" id="delete">delete</button></td>
        </tr>
        `;
    }
    document.getElementById('tbody').innerHTML = table;
    let btn_delete_all = document.getElementById('deleteall')
    if (storageProduct.length > 0) {
        btn_delete_all.innerHTML = `<button onclick="deletealldata()">Delete All (${storageProduct.length})</button>`;
    } else {
        btn_delete_all.innerHTML = '';
    }
}

function delete_element(i) {
    storageProduct.splice(i, 1);
    localStorage.product = JSON.stringify(storageProduct);
    showdata();
}

function delete_all_data() {
    storageProduct.splice(0);
    localStorage.clear();
    showdata();
}

function updatedata(i) {
    title.value = storageProduct[i].title;
    price.value = storageProduct[i].price;
    taxes.value = storageProduct[i].taxes;
    ads.value = storageProduct[i].ads;
    discount.value = storageProduct[i].discount;
    gettotal();
    count.style.display = 'none';
    submit.innerHTML = 'Update'
    mood = 'update';
    tmp = i;
    scroll({
        top: 0,
        behavior: 'smooth',
    })
}

let searchmood = 'title';

function getsearchmood(id) {
    let search = document.getElementById('search');
    if (id == 'searchtitle') {
        searchmood = 'title';
        search.placeholder = 'Search By title';
    } else {
        searchmood = 'category';
        search.placeholder = 'Search By Category';
    }
    search.focus();
    search.value = '';
    showdata();
}

function searchdata(value) {
    let table = '';
    if (searchmood == 'title') {
        for (let i = 0; i < storageProduct.length; i++) {
            if (storageProduct[i].title.includes(value.toLowerCase())) {
                table += `
                    <tr> 
                        <td>${i}</td>
                        <td>${storageProduct[i].title}</td>
                        <td>${storageProduct[i].price}</td>
                        <td>${storageProduct[i].taxes}</td>
                        <td>${storageProduct[i].ads}</td>
                        <td>${storageProduct[i].discount}</td>
                        <td>${storageProduct[i].total}</td>
                        <td>${storageProduct[i].category}</td>
                        <td><button onclick="updatedata(${i})" id="update">update</button></td>
                        <td><button onclick="deletedata(${i})" id="delete">delete</button></td>
                    </tr>
                `;
            }
        }
    } else {
        for (let i = 0; i < storageProduct.length; i++) {
            if (storageProduct[i].category.includes(value.toLowerCase()))
                table += `
                <tr> 
                    <td>${i}</td>
                    <td>${storageProduct[i].title}</td>
                    <td>${storageProduct[i].price}</td>
                    <td>${storageProduct[i].taxes}</td>
                    <td>${storageProduct[i].ads}</td>
                    <td>${storageProduct[i].discount}</td>
                    <td>${storageProduct[i].total}</td>
                    <td>${storageProduct[i].category}</td>
                    <td><button onclick="updatedata(${i})" id="update">update</button></td>
                    <td><button onclick="deletedata(${i})" id="delete">delete</button></td>
                </tr>
            `;
        }
    }
    document.getElementById('tbody').innerHTML = table;
}