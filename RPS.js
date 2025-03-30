let userScore = 0;
let compScore = 0;

const choices = document.querySelectorAll(".choice");
const msg = document.querySelector("#msg");
const userScorePara = document.querySelector("#user-score");
const compScorePara = document.querySelector("#comp-score");


const getComputerChoice = () =>{
    const options = ["rock", "paper", "scissor"];
    const randomIndex = Math.floor(Math.random() * 3);
    return options[randomIndex];
};

const drawGame = () => {
    //console.log("game was draw.");
    msg.innerText = "Its a Draw and excitment increases!";
    msg.style.backgroundColor = "#081b31";
};

showWinner = (userWin, compChoice, userChoice) => {
    if (userWin) {
        userScore++;
        userScorePara.innerText = userScore;
        //console.log ("You Win");
        msg.innerText = `You Win ${userChoice} beats ${compChoice}`;
        msg.style.backgroundColor = "green";
    } 
    else {
        compScore++;
        compScorePara.innerText = compScore;
        //console.log ("oops! better luck next time.");
        msg.innerText = `oops! better luck next time ${compChoice} beats ${userChoice}`;
        msg.style.backgroundColor = "red";
    }
}

const playGame = (userChoice, userWin) => {
    console.log("user choice = ", userChoice);
    //Generate computer choice ->modular way of programming ; making small small functions
    const compChoice = getComputerChoice();
    console.log ("computer choice = ", compChoice);

    if(userChoice === compChoice) {
        drawGame();
    }
    else{
        let userWin = true;
        if (userChoice === "rock"){
            //scissor, paper
            userWin = compChoice === "paper" ? false : true;
        }
        else if (userChoice === "paper"){
            //rock, scissor
            userWin = compChoice === "scissor" ? false : true;
        }
        else{
            //rock, paper
            userWin = compChoice === "rock" ? false : true;
        }
        showWinner(userWin, userChoice, compChoice);
    }
}

choices.forEach((choice) => {
    // console.log(choice);
    choice.addEventListener("click", () => {
        const userChoice = choice.getAttribute("id");
        console.log("choice was clicked" , userChoice);
        playGame(userChoice);
    });
});
 
