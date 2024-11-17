<?php
  require '../menu/modelo.php';
  
  $saikoModel = new saiko_Model();
  $inventario = $saikoModel->getProducto();
?>
<!DOCTYPE html>

<head>
    <meta charset="UTF-8">
    <meta http-equiv= "X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content ="width=device-width, initial-scale=1.0">
    <title>Ingredientes Menu</title>
    <link rel = "stylesheet" href= "style.css">
    <script src="https://code.jquery.com/jquery-3.6.4.min.js"></script>
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
    <section class = "adios">
      <a id="flecha" href="http://localhost/saiko/Menu/Principal" class="logo"><img src="../../imagenes/flecha.png" alt="" width="60" height="60"></a>
      <section class = table>
        <article class="table__header menu">
          <div class="select" style="width:200px;">
            <select id="id" name="id">
              <option value="">Seleccionar Producto</option>
              <?php foreach ($inventario as $ingrediente) :?>

              <?php echo "<option value='".$ingrediente['Id_producto']."'>".$ingrediente['Id_producto']." - ".$ingrediente['nombre_producto']."</option>";?>

              <?php endforeach; ?>
            </select>
          </div>
          <ul>
            <li id = "aca">
            </li>
          <ul>
        </article >
        
        <article class="table__body">
          <table id= "tabla">
            
          </table>
        </article>

        <script>
          // Manejar el cambio en el select
          $('#id').change(function() {
            // Obtener el valor seleccionado
            var selectedIngr = $(this).val();
            // Realizar una solicitud AJAX para obtener los Productos
            $.ajax({
              type: 'POST',
              url: 'obtener.php', // Reemplaza con el nombre de tu archivo PHP
              data: { id: selectedIngr },
              success: function(data) {
                // Actualizar el contenido de Productos-container con la respuesta
                $('#tabla').html(data);
              }
            });
            $.ajax({
              type: 'POST',
              url: 'obtener2.php', // Reemplaza con el nombre de tu archivo PHP
              data: { id: selectedIngr },
              success: function(data) {
                // Actualizar el contenido de Productos-container con la respuesta
                $('#aca').html(data);
              }
            });
          });
        </script>
      </section>
    </section>

  </body>
</html>