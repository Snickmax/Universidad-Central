<?php
require_once 'modelo.php';


class saiko_controller {
    private $model;

    public function __construct() {
        $this->model = new saiko_model();
    }

    public function agregarIngrediente() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $nombre = $_POST['nombre'];
        $cantidad = $_POST['cantidad'];
        $boolean = true;
        $saikoModel = new saiko_Model();
        $inventario = $saikoModel->getInventario();
        foreach ($inventario as $ingrediente) :
            if ($nombre == $ingrediente['nombre_ingrediente']) {
                $boolean = false;
                break;
            }
        endforeach; 

        if ($boolean){
            $resultado = $this->model->insertInventario($nombre, $cantidad);
        }
    }

    public function editarIngrediente() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['id'];
        $nombre = $_POST['nombre'];
        $cantidad = $_POST['cantidad'];
        $resultado = $this->model->updateInventario($id,$nombre,$cantidad);
    }

    public function eliminarIngrediente() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['id'];
        $resultado = $this->model->deleteInventario($id);
    }
}

$saikoController = new saiko_controller();

if ($_GET) {
    $action = $_GET['action'];
    switch ($action) {
        case 'insertar':
            $saikoController->agregarIngrediente();
            break;
        case 'actualizar':
            $saikoController->editarIngrediente();
            break;
        case 'eliminar':
            $saikoController->eliminarIngrediente();
            break;
    }
}
else {
}   
?>
<meta http-equiv="Refresh" content="0; url='http://localhost/saiko/Inventario/Principal/'" />