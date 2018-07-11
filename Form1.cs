using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Linq;

namespace XML_Adresar
{
    public partial class FormXml : Form
    {
        string Putanja = "Adresar.xml";
        string Kontakti = "Kontakti";
        string Kontakt = "Kontakt";
        string Ime = "Ime";
        string Prezime = "Prezime";
        string Adresa = "Adresa";
        string email = "E-mail";
        string Tel = "Telefon";
        string Napomena = "Napomena";

        //komentar da vidim šta se dešava kad napravim branch

        // komentar za dodatak2

        //valjda sam u dodatku 2_2

        //opet smo u 2_2

        public FormXml()
        {
            InitializeComponent();
        }


        private void FormXml_Load(object sender, EventArgs e)
        {
            if (!(File.Exists(Putanja)))
            {
                XDocument _doc = new XDocument(
                    new XDeclaration("1.0", "UTF-8", "yes"),
                    new XElement("Kontakti")
                    );
                _doc.Save(Putanja);                
            }
            try
            {
                DataSet dataSet = new DataSet();
                dataSet.ReadXml(Putanja);
                dgvXML.DataSource = dataSet.Tables[0];
            }
            catch(Exception ex) { MessageBox.Show("XML nema podataka dodajte podatke!"); }
            finally
            {

            }
        }

        private void btn_dodaj_Click(object sender, EventArgs e)
        {
            XDocument _doc = XDocument.Load(Putanja);
            _doc.Element(Kontakti).Add(
                new XElement(Kontakt,
                new XElement(Ime, txt_Ime.Text),
                new XElement(Prezime, txt_Prezime.Text),
                new XElement(Adresa, txt_Adresa.Text),
                new XElement(email, txt_Email.Text),
                new XElement(Tel, txt_Telefon.Text),
                new XElement(Napomena, txt_Napomena.Text)
                ));
            _doc.Save(Putanja);

            DataSet dataSet = new DataSet();
            dataSet.ReadXml(Putanja);
            dgvXML.DataSource = dataSet.Tables[0];

            txt_Ime.Text = "";
            txt_Prezime.Text = "";
            txt_Adresa.Text = "";
            txt_Email.Text = "";
            txt_Telefon.Text = "";
            txt_Napomena.Text = "";
            txt_Ime.Focus();
        }

        private void dgvXML_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            int RowIndex = e.RowIndex;
            txt_Ime.Text = dgvXML.Rows[RowIndex].Cells[0].Value.ToString();
            txt_Prezime.Text = dgvXML.Rows[RowIndex].Cells[1].Value.ToString();
            txt_Adresa.Text = dgvXML.Rows[RowIndex].Cells[2].Value.ToString();
            txt_Email.Text = dgvXML.Rows[RowIndex].Cells[3].Value.ToString();
            txt_Telefon.Text = dgvXML.Rows[RowIndex].Cells[4].Value.ToString();
            txt_Napomena.Text = dgvXML.Rows[RowIndex].Cells[5].Value.ToString();
        }
    }
}
