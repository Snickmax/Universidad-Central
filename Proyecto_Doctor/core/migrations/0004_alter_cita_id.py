# Generated by Django 5.0.6 on 2024-06-27 00:39

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('core', '0003_alter_cita_id'),
    ]

    operations = [
        migrations.AlterField(
            model_name='cita',
            name='id',
            field=models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID'),
        ),
    ]
