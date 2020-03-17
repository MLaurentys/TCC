"use strict"

//Defines
var play_button = "<button id=\"generate\" onclick=\"make_play()\">Make Move</button>"
function make_pile(i){return `Size of pile ${i + 1}: <input id=\"pile_${i+1}\" value="0"></input><br>`}
function make_pile_description(ind, val, i){return `<span id=\"pile_ds_${i+1}\">${make_pile_text()}</span><br>`}
function make_pile_text(ind, val, i){return `| ${ind} | ${val} | Remove: <input id=\"rem_${i+1}\" value=\"0\"></input>`}

//Accessors
var num_piles_box = document.getElementById("num_piles")
var piles_defs = document.getElementById("piles")
var board = document.getElementById("board")

//global vars
var num_piles = 0
var total_piles = 0
var piles_vals = []
var active_piles = 0

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
        let pile_ind = pad(5, i+1, 1)
        let pile_val = pad(9, val, 1)
        let element = make_pile_description(pile_ind, pile_val, i)
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
    document.getElementById(`pile_ds_${pile_ind+1}`).innerHTML = pile_text(pile_ind, pile_rem)
}

function pad(pad_total, str, pad_right){
    let sb = ""
    for (let i = 0; i < pad_total; i++) {sb+="_"}
    sb+=str
    for (let i = 0; i < pad_right; i++) {sb+="_"}
    return String((sb).slice(-pad_total))
}