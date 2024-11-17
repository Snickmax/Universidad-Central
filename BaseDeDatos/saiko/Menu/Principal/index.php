<?php
  require '../menu/modelo.php';
  
  $saikoModel = new saiko_Model();
  $menu = $saikoModel->getProducto();
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
          <li><a href="http://localhost/saiko/Menu/Agregar_producto/">Agregar Productos</a></li>
          <li><a href="http://localhost/saiko/Menu/Editar_Productos/">Editar/Eliminar Productos</a></li>
          <li><a href="http://localhost/saiko/Menu/vista/">Ver productos</a></li>
        <ul>
      </article >
        
      <article class="table__body">
        <table id= "tabla">
          <tr id= "thead">
              <th> Id <span class="icon-arrow">&UpArrow;</span></th>
                <th> Producto <span class="icon-arrow">&UpArrow;</span></th>
                <th> Precio del Producto <span class="icon-arrow">&UpArrow;</span></th>
          </tr>
          <?php foreach ($menu as $producto) : ?>
          <tr id="tbody">
            <td><?php echo $producto['Id_producto']; ?></td>
            <td><?php echo $producto['nombre_producto']; ?></td>
            <td><?php echo "$".$producto['precio_producto']; ?></td>
          </tr>
          <?php endforeach; ?>
        </table>
      </article>
    </section>

  </body>
</html>