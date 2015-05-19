function countBackwards(number)
{
	var result="";
	
	for(var i = number; i>0; i--)
		result += i;
	return result;
}

 function getText()
 {
	var txtInput = document.getElementById("txtInput");
	
	var userInput = txtInput.value;
	
	var divDisplay = document.getElementById("divDisplay");
	
	var counted = countBackwards(userInput)
	
	divDisplay.innerHTML = "<h3>" + counted + "</h3>";
 }

function init()
{
	var btnDemo = document.getElementById("btnDemo");
	btnDemo.onclick = getText;
	alert("Hello");
}

window.onload = init;