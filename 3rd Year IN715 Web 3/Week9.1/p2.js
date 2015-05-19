function setBorder()
{
	var list = document.getElementById("ulAnimals");
	
	list.style.border = "1px solid black";
	list.style.backgroundColor = "orange";
	list.style.width = "50%";
	list.style.marginLeft = "20%";
}


function init()
{
	var btnDemo = document.getElementById("btnCSSDemo");
	btnDemo.onclick = setBorder;
	alert("Hello");
}

window.onload = init;