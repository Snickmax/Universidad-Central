<?php
require_once 'modelo.php';


class saiko_controller {
    private $model;

    public function __construct() {
        $this->model = new saiko_model();
    }

    public function agregarProd() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['idVenta'];
        $id2 = $_POST['id2'];
        $name = ' ';
        $cantidad = $_POST['Cantidad'];
        $boolean = true;
        $saikoModel = new saiko_Model();
        $carro = $saikoModel->getcarro();
        if($id2){

            if ($boolean){
                $resultado = $this->model->insertProd($id, $id2,$cantidad);
            }
            
        }
        echo '<meta http-equiv="Refresh" content="';
            echo "0; url='";
            echo "http://localhost/saiko/Venta/Principal/index.php?id=".$id."'";
            echo '" />';
    }

    public function eliminarProd() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $id = $_POST['idVenta'];
        $id2 = $_POST['id2'];
        $cantidad = $_POST['Cantidad'];
        $resultado = $this->model->deleteProd($id, $id2,$cantidad);
        echo '<meta http-equiv="Refresh" content="';
        echo "0; url='";
        echo "http://localhost/saiko/Venta/Principal/index.php?id=".$id."'";
        echo '" />';
    }

    public function crearventa() {
        // Obtiene los datos del formulario y los inserta en la base de datos
        $resultado = $this->model->crearVenta();
    }

    public function BuscarId(){

        $saikoModel = new saiko_Model();
        $id = $saikoModel->buscarId();

        foreach ($id as $idd) :
            echo '<meta http-equiv="Refresh" content="';
            echo "0; url='";
            echo "http://localhost/saiko/Venta/Principal/index.php?id=".$idd['id']."'";
            echo '" />';
        endforeach;
    }

    public function vender(){
        $id = $_POST['idVenta'];

        $saikoModel = new saiko_Model();

        $carro = $saikoModel->getcarr($id);
        $a = $saikoModel->temp();
        
        foreach ($carro as $producto) :
            $prod = $saikoModel->getIng_Prod($producto['Id_producto']);
            foreach ($prod as $ingred) :
                $inv = $saikoModel->gettemp($ingred['Id_ingrediente']);
                foreach ($inv as $ingrediente) :
                    if($ingrediente['cantidad_ingrediente'] > ($ingred['cantidad']*$producto['cantidad'])){
                        $resultado = $this->model->retTemp($ingred['Id_ingrediente'], $ingrediente['cantidad_ingrediente']-($ingred['cantidad']*$producto['cantidad']));
                    }
                    else {
                        $a = $saikoModel->droptemp();
                        echo '<meta http-equiv="Refresh" content="';
                        echo "0; url='";
                        echo "http://localhost/saiko/Venta/Principal/index.php?id=".$id."'";
                        echo '" />';
                        return false; 
                    }
                endforeach;
            endforeach;
        endforeach;
        $a = $saikoModel->droptemp();
        return true; 
    }

    public function vender2(){
        $id = $_POST['idVenta'];
        $suma = 0;
        $saikoModel = new saiko_Model();

        $carro = $saikoModel->getcarr($id);
        
        
        foreach ($carro as $producto) :
            $suma += $producto['precio'];
        endforeach;

        $resultado = $this->model->actualizar($id, $suma);

    }

    public function vender3(){
        $id = $_POST['idVenta'];

        $saikoModel = new saiko_Model();

        $carro = $saikoModel->getcarr($id);
        
        foreach ($carro as $producto) :
            $prod = $saikoModel->getIng_Prod($producto['Id_producto']);
            foreach ($prod as $ingred) :
                $inv = $saikoModel->getinv($ingred['Id_ingrediente']);
                foreach ($inv as $ingrediente) :
                    $resultado = $this->model->retinv($ingred['Id_ingrediente'], $ingrediente['cantidad_ingrediente']-($ingred['cantidad']*$producto['cantidad']));
                endforeach;
            endforeach;
        endforeach;

        echo '<meta http-equiv="Refresh" content="';
        echo "0; url='";
        echo "http://localhost/saiko/Venta/Principal/index.php?id=".$id."'";
        echo '" />';
    }
}

$saikoController = new saiko_controller();

if ($_GET) {
    $action = $_GET['action'];
    switch ($action) {
        case 'insertar':
            $saikoController->agregarProd();
            break;
        case 'eliminar':
            $saikoController->eliminarProd();
            break;
        case 'newventa':
            $saikoController->crearventa();
            $saikoController->BuscarId();
            break;  
        case 'vender':
            if ($saikoController->vender()) {
                $saikoController->vender2();
                $saikoController->vender3();
            }
            
            break;  
    }
}
else {
}   
?>