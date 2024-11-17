<?php
require '../menu/modelo.php';

if (isset($_POST['id'])) {
    $id = $_POST['id'];

    $saikoModel = new saiko_model();

    $saiko = $saikoModel->getProd($id);

    foreach ($saiko as $cant_prod) {
        echo "<div class ='input-box hola'>";
        echo "<input type='text' placeholder='Producto' name='nombre' value = ".$cant_prod['nombre_producto']." required>";
        echo "<input type='number' placeholder='Precio' name='precio' value = ".$cant_prod['precio_producto']." required>";
        echo "<button type='submit' class='btn'>Editar</button>";
        echo "<button type='submit' formaction='http://localhost/saiko/Menu/menu/controlador.php?action=eliminar' class='btn'>Eliminar</button>";
        echo "<button type='submit' formaction='http://localhost/saiko/Menu/ingredientes?id=".$id."' class='btn'>Editar Ingredientes</button>";
        echo "</div>";
    }
} else {
    echo 'Seleccione un producto.';
}
?>
