<?php

class saiko_model {
    private $conexion;

    public function __construct() {
        // Realiza la conexión a la base de datos
        $this->conexion = new PDO("mysql:host=localhost;dbname=saiko_sushi", "root", "");
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
        $query = "SELECT * FROM `inventario` where Id_ingrediente = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->execute();
        $result = $statement->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }


    public function insertInventario($nombre,$cantidad) {
        // Inserta un nuevo Ingrediente en la base de datos
        $query = "INSERT INTO inventario (Id_ingrediente , nombre_ingrediente, cantidad_ingrediente) VALUES ( default, :nombre, :cantidad)";
        $statement = $this->conexion->prepare($query);

        $statement->bindParam(':nombre', $nombre);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }

    public function updateInventario($id,$nombre,$cantidad) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "UPDATE inventario SET cantidad_ingrediente = :cantidad, nombre_ingrediente = :nombre WHERE Id_ingrediente = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $statement->bindParam(':nombre', $nombre);
        $statement->bindParam(':cantidad', $cantidad);
        $result = $statement->execute();
        return $result;
    }

    public function deleteInventario($id) {
        // Actualiza los datos de un profesor en la base de datos
        $query = "DELETE FROM `inventario` WHERE `inventario`.`Id_ingrediente` = :id";
        $statement = $this->conexion->prepare($query);
        $statement->bindParam(':id', $id);
        $result = $statement->execute();
        return $result;
    }
}
?>