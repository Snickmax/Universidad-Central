<?php

class saiko_model {
    private $conexion;

    public function __construct() {
        // Realiza la conexión a la base de datos
        $this->conexion = new PDO("mysql:host=localhost;dbname=saiko_sushi", "root", "");
    }

    public function getProducto() {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `menu`";
        
        $statement = $this->conexion->query($query);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getProd($id) {
        // Obtiene todos los cant_ingred de la base de datos
        $query = "SELECT * FROM `menu` where Id_producto = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getInventario() {
        // Obtiene todos los Ingredientes de la base de datos
        $query = "SELECT * FROM `inventario`";
        
        $statement = $this->conexion->query($query);
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }

    public function getingred($id) {
        // Obtiene todos los cant_ingred de la base de datos
        $query = "SELECT * FROM `inventario_menu` where Id_producto = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }
    public function getingrediente($id) {
        // Obtiene todos los cant_ingred de la base de datos
        $query = "SELECT * FROM `inventario` where Id_ingrediente = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }
    
    public function insertProducto($nombre,$precio) {
        // Inserta un nuevo Ingrediente en la base de datos
        $query = "INSERT INTO menu (Id_producto , nombre_producto, precio_producto) VALUES ( default, :nombre, :precio)";
        $statement = $this->conexion->prepare($query);

        $statement->bindParam(':nombre', $nombre);
        $statement->bindParam(':precio', $precio);
        $result = $statement->execute();
        return $result;
    }

    public function updateProducto($id,$nombre,$precio) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE menu SET precio_producto = :precio, nombre_producto = :nombre WHERE Id_producto = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':nombre', $nombre);
        $statement->bindParam(':precio', $precio);
        $result = $statement->execute();
        return $result;
    }

    public function deleteProducto($id) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "DELETE FROM `menu` WHERE `menu`.`Id_producto` = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $result = $statement->execute();
        return $result;
    }

    public function insertIng($id,$id2,$cantidad) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "INSERT INTO `inventario_menu`(`Id_producto`, `Id_ingrediente`, `cantidad`) VALUES ( :id , :id2 , :cantidad )";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':id2', $id2);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }

    public function updateIng($id,$id2,$cantidad) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE `inventario_menu` SET `cantidad`= :cantidad WHERE `Id_producto`= :id and `Id_ingrediente`= :id2 ";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':id2', $id2);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }


    public function deleteIng($id, $id2) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "DELETE FROM inventario_menu WHERE `inventario_menu`.`Id_producto` = :id AND `inventario_menu`.`Id_ingrediente` = :id2";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':id2', $id2);
        $result = $statement->execute();
        return $result;
    }
}
?>