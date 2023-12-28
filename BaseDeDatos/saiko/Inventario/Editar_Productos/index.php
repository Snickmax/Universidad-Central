<?php
  require '../inventario/modelo.php';
  
  $saikoModel = new saiko_Model();
  $inventario = $saikoModel->getInventario();
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv= "X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content ="width=device-width,
    initial-scale=1.0">
    <title>Editar</title>
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
      <a id="flecha" href="http://localhost/saiko/Inventario/Principal" class="logo"><img src="../../imagenes/flecha.png" alt="" width="60" height="60"></a>
      <article class = "wrapper">
        <form action="http://localhost/saiko/Inventario/inventario/controlador.php?action=actualizar" method="POST">
          <h1>Editar Ingrediente</h1>
          <div class="select" style="width:200px;">
            <select id="id" name="id">
              <option value="">Seleccionar Producto</option>
              <?php foreach ($inventario as $ingrediente) :?>

              <?php echo "<option value='".$ingrediente['Id_ingrediente']."'>".$ingrediente['Id_ingrediente']." - ".$ingrediente['nombre_ingrediente']."</option>";?>

              <?php endforeach; ?>
            </select>
          </div>
          <div id="ingredientes-container">
          <!-- La información de los ingredientes se mostrará aquí -->
          </div>
        </form>
      </article>
        <script>
          // Manejar el cambio en el select
          $('#id').change(function() {
            // Obtener el valor seleccionado
            var selectedIngr = $(this).val();
            // Realizar una solicitud AJAX para obtener los ingredientes
            $.ajax({
              type: 'POST',
              url: 'obtener.php', // Reemplaza con el nombre de tu archivo PHP
              data: { id: selectedIngr },
              success: function(data) {
                // Actualizar el contenido de ingredientes-container con la respuesta
                $('#ingredientes-container').html(data);
              }
            });
          });
        </script>
    </section>
</body>

</html>