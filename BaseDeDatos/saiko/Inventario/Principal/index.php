<?php
  require '../inventario/modelo.php';
  
  $saikoModel = new saiko_Model();
  $inventario = $saikoModel->getInventario();
?>
<!DOCTYPE html>

<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tabla</title>
    <link rel="stylesheet" href="style.css">
  </head>

  <body>
    <header>
        <table class = "header">
        <tr>
          <th>
            <a href="http://localhost/saiko/Principal"><img src="../../imagenes/logo.jpg" alt="" width="150px"></a>
          </th>
          <th>
            <div> SAIKO SUSHI</div>
          </th>
          <th>
          </th>
        </tr>
      </table>
    </header>

    <section class = table>
      <article class="table__header menu">
        <ul>
          <li><a href="http://localhost/saiko/Inventario/Agregar_producto/">Agregar Ingredientes</a></li>
          <li><a href="http://localhost/saiko/Inventario/Editar_Productos/">Editar/Eliminar Ingredientes</a></li>
        <ul>
      </article >
        
      <article class="table__body">
        <table id= "tabla">
          <tr id= "thead">
              <th> Id <span class="icon-arrow">&UpArrow;</span></th>
                <th> Ingrediente <span class="icon-arrow">&UpArrow;</span></th>
                <th> Cantidad de ingrediente <span class="icon-arrow">&UpArrow;</span></th>
          </tr>
          <?php foreach ($inventario as $Ingrediente) : ?>
          <tr id="tbody">
            <td><?php echo $Ingrediente['Id_ingrediente']; ?></td>
            <td><?php echo $Ingrediente['nombre_ingrediente']; ?></td>
            <td><?php echo $Ingrediente['cantidad_ingrediente']; ?></td>
          </tr>
          <?php endforeach; ?>
        </table>
      </article>
    </section>

  </body>
</html>