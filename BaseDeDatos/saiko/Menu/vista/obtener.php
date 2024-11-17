<?php
require '../menu/modelo.php';

if (isset($_POST['id'])) {
    $id = $_POST['id'];

    $saikoModel = new saiko_model();

    $inventario = $saikoModel->getingred($id);

    echo "<tr id= 'thead'>";
    echo "      <th> Ingrediente <span class='icon-arrow'>&UpArrow;</span></th>";
    echo "      <th> Cantidad de ingrediente <span class='icon-arrow'>&UpArrow;</span></th>";
    echo "</tr>";
    foreach ($inventario as $Ingrediente) :
        $bra = $saikoModel->getingrediente($Ingrediente['Id_ingrediente']);
        foreach ($bra as $lol) {
            $idddd =  $lol['nombre_ingrediente'];
        }
        echo "<tr id='tbody'>";
        echo "  <td>";
        echo $idddd;
        echo "</td>";
        echo "  <td>";
        echo $Ingrediente['cantidad']; 
        echo "</td>";
        echo "</tr>";
    endforeach;
} else {
    echo 'Seleccione un producto.';
}
?>
