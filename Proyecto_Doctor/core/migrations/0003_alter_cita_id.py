# Generated by Django 5.0.6 on 2024-06-27 00:35

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0002_paciente_cita'),
    ]

    operations = [
        migrations.AlterField(
            model_name='cita',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
