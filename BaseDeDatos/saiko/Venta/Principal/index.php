<?php
  require '../venta/modelo.php';
  
  $saikoModel = new saiko_Model();
  $id = $_GET['id'];
  $menu = $saikoModel->getProducto();
  $carro = $saikoModel->getcarr($id);
  $names = '';
  $suma = 0;
  
?>
<!DOCTYPE html>

<head>
    <meta charset="UTF-8">
    <meta http-equiv= "X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content ="width=device-width, initial-scale=1.0">
    <title>Ingredientes Menu</title>
    <link rel = "stylesheet" href= "style.css">
</head>

<html lang="en">

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
    <section>
      <section class = table>
        <form action="" method="post">
          <?php echo "<input type='text' id='idVenta' name='idVenta' value='".$id."' required style= 'display: none;' >"?>
          <article class="table__header menu">
            <div class="select" style="width:200px;">
            <select id="id2" name="id2">
              <option value="">Seleccionar Producto</option>
              <?php foreach ($menu as $ingrediente) :?>

              <?php echo "<option value='".$ingrediente['Id_producto']."'>".$ingrediente['nombre_producto']. " - $".$ingrediente['precio_producto']."</option>";?>
              
              <?php endforeach; ?>
            </select>
            </div>
            <div class ='input-box hola'>
              <input type='number' placeholder='Cantidad' id='Cantidad'  name='Cantidad' required>
            </div><br>
            <ul>
              <li  id ="aca" class = "wrapper">
                  <button type='submit' formaction='http://localhost/saiko/Venta/venta/controlador.php?action=insertar' class='btn'>agregar</button>
                  <button type='submit' formaction='http://localhost/saiko/Venta/venta/controlador.php?action=eliminar' class='btn'>eliminar</button>
                  <button type='submit' formaction='http://localhost/saiko/Venta/venta/controlador.php?action=vender' class='btn'>Vender</button>
              </li>
            <ul>
          </article >
        </form>
        <article class="table__body">
        <table id= "tabla">
          <tr id= "thead">
              <th> Producto <span class="icon-arrow">&UpArrow;</span></th>
                <th> cantidad <span class="icon-arrow">&UpArrow;</span></th>
                <th> Precio <span class="icon-arrow">&UpArrow;</span></th>
          </tr>
          <?php foreach ($carro as $producto) : ?>
          <tr id="tbody">
            <td><?php echo $producto['nombre_producto']; ?></td>
            <td><?php echo $producto['cantidad']; ?></td>
            <td><?php echo "$".$producto['precio'];?></td>
            <?php $suma +=  $producto['precio']; ?>
          </tr>
          <?php endforeach; ?>
          <tr>
            <td></td>
            <td style= 'text-align: right;'>Total:</td>
            <td><?php echo "$".$suma?></td>
          </tr>
        </table>
      </article>
      </section>
    </section>
    

  </body>
</html>