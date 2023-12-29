
function normal(x, mu, sigma) {
    const erfValue = math.erf((x - mu) / (sigma * math.sqrt(2)));
    return 0.5 * (1 + erfValue);
}

function calc() {
    const mu = document.getElementById("mu").value;
    const sigma = document.getElementById("sigma").value;
    const valor = document.getElementById("valor");
    const valor2 = document.getElementById("valor2");
    let sel = document.getElementById("seleccion").value;
        if (sel == "menor") {
            const x = document.getElementById("nummenor").value;
            const cdfValue = normal(x, mu, sigma);
            valor.value = cdfValue.toFixed(4);
            valor2.value = (cdfValue*100).toFixed(2);
        }
        else if (sel == "mayor") {
            const x = document.getElementById("nummayor").value;
            const cdfValue = normal(x, mu, sigma);
            valor.value = (1-cdfValue).toFixed(4);
            valor2.value = ((1-cdfValue)*100).toFixed(2);
        }
        else if (sel == "entre") {
            const x = document.getElementById("entremayor").value;
            const cdfValue = normal(x, mu, sigma);
            const x2 = document.getElementById("entremenor").value;
            const cdfValue2 = normal(x2, mu, sigma);
            valor.value = (cdfValue - cdfValue2).toFixed(4);
            valor2.value = ((cdfValue-cdfValue2)*100).toFixed(2);
        }
}

function limp() {
    document.getElementById("nummayor").value = "";
    document.getElementById("nummenor").value = "";
    document.getElementById("entremenor").value = "";
    document.getElementById("entremayor").value = "";
    document.getElementById("mu").value = "";
    document.getElementById("sigma").value = "";
    document.getElementById("valor").value = "";
    document.getElementById("valor2").value = "";
}

function select() {
    let sel = document.getElementById("seleccion").value;
    if (sel == "menor") {
        document.getElementById("seleccion_menor").style.display = "inline";
        document.getElementById("seleccion_mayor").style.display = "none";
        document.getElementById("seleccion_entre").style.display = "none";
        document.getElementById("nummayor").value = "";
        document.getElementById("entremenor").value = "";
        document.getElementById("entremayor").value = "";
        console.log(sel);
    }
    else if (sel == "mayor") {
        document.getElementById("seleccion_mayor").style.display = "inline";
        document.getElementById("seleccion_menor").style.display = "none";
        document.getElementById("seleccion_entre").style.display = "none";
        document.getElementById("nummenor").value = "";
        document.getElementById("entremenor").value = "";
        document.getElementById("entremayor").value = "";
        console.log(sel);
    }
    else if (sel == "entre") {
        document.getElementById("seleccion_entre").style.display = "inline";
        document.getElementById("seleccion_menor").style.display = "none";
        document.getElementById("seleccion_mayor").style.display = "none";
        document.getElementById("nummayor").value = "";
        document.getElementById("nummenor").value = "";
        console.log(sel);
    }
}

  