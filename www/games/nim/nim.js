"use strict"

//Defines
var play_button = "<button id=\"generate\" onclick=\"make_play()\">Make Move</button>"
function make_pile(i){return `Size of pile ${i + 1}: <input id=\"pile_${i+1}\" value="0"></input><br>`}
function make_pile_description(i){return `<span id=\"pile_ds_${i+1}\">${make_pile_text(i)}</span><br>`}

//Helpers
function make_pile_text(i){
    let ind = pad(5, i+1, 1)
    let val = pad(9, piles_vals[i], 1)
    return `| ${ind} | ${val} | Remove: <input id=\"rem_${i+1}\" value=\"0\"></input>`
}
function pad(pad_total, str, pad_right){
    let sb = ""
    for (let i = 0; i < pad_total; i++) {sb+="_"}
    sb+=String(str)
    for (let i = 0; i < pad_right; i++) {sb+="_"}
    return String((sb).slice(-pad_total))
}
function read_one_int(str, si){
    
}
//Accessors
var num_piles_box = document.getElementById("num_piles")
var piles_defs = document.getElementById("piles")
var board = document.getElementById("board")

//global vars
var num_piles = 0
var total_piles = 0
var piles_vals = []
var active_piles = 0

function createFromString(){

}
function change_number(newValue){
    num_piles = parseInt(newValue)
    num_piles_box.value = num_piles
    make_piles_defs()
}
function make_piles_defs(){
    piles_defs.innerHTML = ""
    for (let i = 0; i < num_piles; i++) {
        let element = make_pile(i)
        piles_defs.innerHTML += element
    }
}
function make_board(){
    total_piles = num_piles 
    active_piles = 0
    board.innerHTML = "Piles | Remaining <br><br>"
    for (let i = 0; i < num_piles; i++) {
        let val = document.getElementById(`pile_${i+1}`).value
        piles_vals.push(val)
        if (val > 0) active_piles++
        let element = make_pile_description(i)
        board.innerHTML += element
    }
    board.innerHTML += play_button
}
function make_play(){
    let pile = -1
    let to_remove = -1
    for (let i = 0; i < total_piles; i++) {
        let to_rem = document.getElementById(`rem_{i+1}`).value
        if(to_rem != 0){
            if(pile != -1 || to_rem > piles_val[i]) return
            pile = i
            to_remove = to_rem
        }
    }
    finish_play(pile, to_remove)
}
function finish_play(pile_ind, pile_rem){
    piles_vals[pile_ind] -= pile_rem
    document.getElementById(`pile_ds_${pile_ind+1}`).innerHTML = make_pile_text(pile_ind)
}

