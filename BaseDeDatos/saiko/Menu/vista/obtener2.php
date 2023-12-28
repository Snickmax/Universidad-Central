<?php

if (isset($_POST['id'])) {
    $id = $_POST['id'];
    echo "<a href='http://localhost/saiko/Menu/ingredientes/index.php?id=".$id."'>Editar Ingredientes</a>";
} else {
    echo 'Seleccione un producto.';
}
?>
