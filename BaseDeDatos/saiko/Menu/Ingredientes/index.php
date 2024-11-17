<?php
  require '../menu/modelo.php';
  
  $saikoModel = new saiko_Model();
  $inventario = $saikoModel->getInventario();
  $action = $_GET['id'];
  $Ingredientes = $saikoModel->getingred($action);
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv= "X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content ="width=device-width, initial-scale=1.0">
    <title>Ingrediente</title>
    <link rel = "stylesheet" href= "style.css">
    <script src="https://code.jquery.com/jquery-3.6.4.min.js"></script>
</head>

<body>
    <header class = "header">
      <table>
        <tr>
          <th>
            <a id="logo" href="http://localhost/saiko/Principal"><img src="../../imagenes/logo.jpg" alt="" width="150px"></a>
          </th>
          <th>
            <div class = "hola"> SAIKO SUSHI</div>
          </th>
          <th>
          </th>
        </tr>
      </table>
    </header>

    <section >
      <a id="flecha" href="http://localhost/saiko/Menu/Principal" class="logo"><img src="../../imagenes/flecha.png" alt="" width="60" height="60"></a>
      <article class = "wrapper">
        <form action="http://localhost/saiko/Menu/menu/controlador.php?action=actualizar" method="POST">
          <?php echo "<input type='text' id='idProd' name='idProd' value='".$action."' required style= 'display: none;' >"?>
          <h1>Editar Ingredientes</h1>
          <div class="select" style="width:200px;">
            <select id = "idIngred" name = "idIngred">
              <option value="">Seleccionar Ingredientes</option>
              <?php foreach ($inventario as $ingrediente) :?>
                
              <?php echo "<option value='".$ingrediente['Id_ingrediente']."'>".$ingrediente['Id_ingrediente']." - ".$ingrediente['nombre_ingrediente']."</option>";?>

              <?php endforeach; ?>
            </select>
          </div>
          <div id="ingredientes-container">
            <div class ='input-box hola'>
              <input type='text' placeholder='Cantidad' id='Cantidad'  name='Cantidad' required>
            </div><br>
            <div id= "tableton">
              <table id= "tabla">
                <tr id= "thead">
                  <th>Nombre</th>
                  <th>cantidad</th>
                </tr>
                <?php foreach ($Ingredientes as $Ingrediente) : ?>
                  <?php $bra = $saikoModel->getingrediente($Ingrediente['Id_ingrediente']);
                  foreach ($bra as $lol) {
                    $idddd =  $lol['nombre_ingrediente'];
                  }
                  ?>
                  <tr id="tbody">
                    <td><?php echo $idddd; ?></td>
                    <td><?php echo $Ingrediente['cantidad']; ?></td>
                  </tr>
                <?php endforeach; ?>
              </table>
            </div>
            <div class ='input-box hola'>
              <button type='submit' formaction='http://localhost/saiko/Menu/menu/controlador.php?action=EditIng' class='btn'>Agregar</button>
              <button type='submit' formaction='http://localhost/saiko/Menu/menu/controlador.php?action=elimIng' class='btn'>Eliminar</button>
            </div>
          </div>
        </form>
      </article>
    </section>
</body>

</html>