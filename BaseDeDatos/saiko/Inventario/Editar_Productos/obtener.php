<?php
require '../inventario/modelo.php';

if (isset($_POST['id'])) {
    $id = $_POST['id'];

    $saikoModel = new saiko_model();

    $saiko = $saikoModel->getingred($id);

    foreach ($saiko as $cant_ingred) {
        echo "<div class ='input-box hola'>";
        echo "<input type='text' placeholder='Ingrediente' name='nombre' value = ".$cant_ingred['nombre_ingrediente']." required>";
        echo "<input type='number' placeholder='Cantidad de ingrediente' name='cantidad' value = ".$cant_ingred['cantidad_ingrediente']." required>";
        echo "<button type='submit' class='btn'>Editar</button>";
        echo "<button type='submit' formaction='http://localhost/saiko/Inventario/inventario/controlador.php?action=eliminar' class='btn'>Eliminar</button>";
        echo "</div>";
    }
} else {
    echo 'Seleccione un producto.';
}
?>
