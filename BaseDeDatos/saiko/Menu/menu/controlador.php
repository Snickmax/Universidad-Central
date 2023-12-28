<?php
require_once 'modelo.php';


class saiko_controller {
    private $model;

    public function __construct() {
        $this->model = new saiko_model();
    }

    public function BuscarId(){
        $nombre = $_POST['nombre'];
        $saikoModel = new saiko_Model();
        $menu = $saikoModel->getProducto();

        foreach ($menu as $Productos) :
            if ($nombre == $Productos['nombre_producto']) {
                return $Productos['Id_producto'];
            }
        endforeach; 
    }

    public function agregarProducto() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $nombre = $_POST['nombre'];
        $precio = $_POST['precio'];
        $boolean = true;
        $saikoModel = new saiko_Model();
        $menu = $saikoModel->getProducto();
        foreach ($menu as $Productos) :
            if ($nombre == $Productos['nombre_producto']) {
                $boolean = false;
                break;
            }
        endforeach; 

        if ($boolean){
            $resultado = $this->model->insertProducto($nombre, $precio);
        }
    }

    public function editarProducto() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['id'];
        $nombre = $_POST['nombre'];
        $precio = $_POST['precio'];
        $resultado = $this->model->updateProducto($id,$nombre,$precio);
    }

    public function eliminarProducto() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['id'];
        $resultado = $this->model->deleteProducto($id);
    }

    public function agregarIng() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['idProd'];
        $id2 = $_POST['idIngred'];
        $cantidad = $_POST['Cantidad'];
        $boolean = true;
        $saikoModel = new saiko_Model();
        $menu = $saikoModel->getingred($id);
        if($id2){
            foreach ($menu as $Ingredientes) :
                if ($id == $Ingredientes['Id_producto'] and $id2 == $Ingredientes['Id_ingrediente'] ) {
                    $boolean = false;
                    break;
                }
            endforeach; 

            if ($boolean){
                $resultado = $this->model->insertIng($id,$id2,$cantidad);
            }
            else {
                $resultado = $this->model->updateIng($id,$id2,$cantidad);
            }
        }
        
        echo '<meta http-equiv="Refresh" content="';
        echo "0; url='";
        echo "http://localhost/saiko/Menu/Ingredientes?id=".$id."'";
        echo '" />';
    }

    public function eliminarIng() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['idProd'];
        $id2 = $_POST['idIngred']; 
        if($id2){
            $resultado = $this->model->deleteIng($id, $id2);
        }
        echo '<meta http-equiv="Refresh" content="';
        echo "0; url='";
        echo "http://localhost/saiko/Menu/Ingredientes?id=".$id."'";
        echo '" />';
    }
}

$saikoController = new saiko_controller();

if ($_GET) {
    $action = $_GET['action'];
    switch ($action) {
        case 'insertar':
            $saikoController->agregarProducto();
            $idddd = $saikoController->BuscarId();
            echo '<meta http-equiv="Refresh" content="';
            echo "0; url='";
            echo "http://localhost/saiko/Menu/ingredientes/index.php?id=".$idddd."'";
            echo '" />';
            break;
        case 'actualizar':
            $saikoController->editarProducto();
            echo '<meta http-equiv="Refresh" content="';
            echo "0; url='";
            echo "http://localhost/saiko/Menu/Principal/'";
            echo '" />';
            break;
        case 'eliminar':
            $saikoController->eliminarProducto();
            echo '<meta http-equiv="Refresh" content="';
            echo "0; url='";
            echo "http://localhost/saiko/Menu/Principal/'";
            echo '" />';
            break;
        case 'EditIng':
            $saikoController->agregarIng();
            break;
        case 'elimIng':
            $saikoController->eliminarIng();
            break;
    }
}
else {
    echo '<meta http-equiv="Refresh" content="';
    echo "0; url='";
    echo "http://localhost/saiko/Menu/Principal/'";
    echo '" />';
}
?>