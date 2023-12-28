<?php

class saiko_model {
    private $conexion;

    public function __construct() {
        // Realiza la conexión a la base de datos
        $this->conexion = new PDO("mysql:host=localhost;dbname=saiko_sushi", "root", "");
    }

    public function getcarro() {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `carrito`";
        
        $statement = $this->conexion->query($query);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getcarr($id) {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `carrito` where Id_venta = :id";
        
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getIng_Prod($id) {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `inventario_menu` where Id_producto = :id";
        
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function gettemp($id) {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `nueva_tabla` where Id_ingrediente = :id";
        
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getinv($id) {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `inventario` where Id_ingrediente = :id";
        
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getProducto() {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `menu`";
        
        $statement = $this->conexion->query($query);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function crearVenta() {
        // Actualiza los datos de un profesor en la base de datos
        $query = "INSERT INTO `registro_venta`(`Id_venta`, `Total`) VALUES (default,0)";
        $statement = $this->conexion->prepare($query);
        $result = $statement->execute();
        return $result;
    }

    public function buscarId() {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT `id`() AS `id`;";
        $statement = $this->conexion->query($query);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function insertProd($id, $id2, $cantidad) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "CALL ActualizarCarrito2( :id , :id2 , :cantidad)";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':id2', $id2);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }


    public function deleteProd($id, $id2, $cantidad) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "CALL ActualizarCarrito( :id , :id2 , :cantidad)";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':id2', $id2);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }

    public function actualizar($id, $suma) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE registro_venta SET Total =:suma WHERE Id_venta  = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':suma', $suma);
        $result = $statement->execute();
        return $result;
    }

    public function temp() {
        // Actualiza los datos de un profesor en la base de datos
        $query = "CREATE TABLE IF NOT EXISTS nueva_tabla AS SELECT * FROM inventario;";
        $statement = $this->conexion->prepare($query);
        $result = $statement->execute();
        return $result;
    }
    public function droptemp() {
        // Actualiza los datos de un profesor en la base de datos
        $query = "DROP TABLE IF EXISTS nueva_tabla;";
        $statement = $this->conexion->prepare($query);
        $result = $statement->execute();
        return $result;
    }

    public function retTemp($id, $suma){
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE nueva_tabla SET cantidad_ingrediente =:suma WHERE Id_ingrediente  = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':suma', $suma);
        $result = $statement->execute();
        return $result;
    }
    public function retinv($id, $suma){
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE inventario SET cantidad_ingrediente =:suma WHERE Id_ingrediente  = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':suma', $suma);
        $result = $statement->execute();
        return $result;
    }
}
?>