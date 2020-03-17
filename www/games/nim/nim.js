"use strict"

var num_piles_box = document.getElementById("num_piles")
var piles = document.getElementById("piles")
var num_piles = 0
function change_number(newValue){
    num_piles = parseInt(newValue)
    num_piles_box.value = num_piles
    make_piles_defs()
}
function make_piles_defs(){
    piles.innerHTML = ""
    for (let i = 0; i < num_piles; i++) {
        let element = `Size of pile ${i + 1}: <input value="0"></input><br>`
        piles.innerHTML += element
    }
}
