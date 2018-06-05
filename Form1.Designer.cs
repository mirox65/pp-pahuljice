namespace XML_Adresar
{
    partial class FormXml
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lbl_Ime = new System.Windows.Forms.Label();
            this.lbl_Naslov = new System.Windows.Forms.Label();
            this.lbl_Napomena = new System.Windows.Forms.Label();
            this.lbl_telefon = new System.Windows.Forms.Label();
            this.lbl_email = new System.Windows.Forms.Label();
            this.lbl_Adresa = new System.Windows.Forms.Label();
            this.lbl_Prezime = new System.Windows.Forms.Label();
            this.txt_Ime = new System.Windows.Forms.TextBox();
            this.txt_Telefon = new System.Windows.Forms.TextBox();
            this.txt_Email = new System.Windows.Forms.TextBox();
            this.txt_Adresa = new System.Windows.Forms.TextBox();
            this.txt_Prezime = new System.Windows.Forms.TextBox();
            this.txt_Napomena = new System.Windows.Forms.TextBox();
            this.btn_dodaj = new System.Windows.Forms.Button();
            this.dgvXML = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dgvXML)).BeginInit();
            this.SuspendLayout();
            // 
            // lbl_Ime
            // 
            this.lbl_Ime.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_Ime.AutoSize = true;
            this.lbl_Ime.Location = new System.Drawing.Point(28, 106);
            this.lbl_Ime.Name = "lbl_Ime";
            this.lbl_Ime.Size = new System.Drawing.Size(50, 25);
            this.lbl_Ime.TabIndex = 0;
            this.lbl_Ime.Text = "Ime:";
            // 
            // lbl_Naslov
            // 
            this.lbl_Naslov.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_Naslov.AutoSize = true;
            this.lbl_Naslov.Font = new System.Drawing.Font("Monotype Corsiva", 26.14286F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lbl_Naslov.Location = new System.Drawing.Point(329, 8);
            this.lbl_Naslov.Name = "lbl_Naslov";
            this.lbl_Naslov.Size = new System.Drawing.Size(327, 75);
            this.lbl_Naslov.TabIndex = 2;
            this.lbl_Naslov.Text = "XML adresar";
            // 
            // lbl_Napomena
            // 
            this.lbl_Napomena.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_Napomena.AutoSize = true;
            this.lbl_Napomena.Location = new System.Drawing.Point(28, 326);
            this.lbl_Napomena.Name = "lbl_Napomena";
            this.lbl_Napomena.Size = new System.Drawing.Size(114, 25);
            this.lbl_Napomena.TabIndex = 3;
            this.lbl_Napomena.Text = "Napomena:";
            // 
            // lbl_telefon
            // 
            this.lbl_telefon.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_telefon.AutoSize = true;
            this.lbl_telefon.Location = new System.Drawing.Point(28, 282);
            this.lbl_telefon.Name = "lbl_telefon";
            this.lbl_telefon.Size = new System.Drawing.Size(126, 25);
            this.lbl_telefon.TabIndex = 4;
            this.lbl_telefon.Text = "Broj telefona:";
            // 
            // lbl_email
            // 
            this.lbl_email.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_email.AutoSize = true;
            this.lbl_email.Location = new System.Drawing.Point(28, 238);
            this.lbl_email.Name = "lbl_email";
            this.lbl_email.Size = new System.Drawing.Size(73, 25);
            this.lbl_email.TabIndex = 5;
            this.lbl_email.Text = "E-mail:";
            // 
            // lbl_Adresa
            // 
            this.lbl_Adresa.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_Adresa.AutoSize = true;
            this.lbl_Adresa.Location = new System.Drawing.Point(28, 194);
            this.lbl_Adresa.Name = "lbl_Adresa";
            this.lbl_Adresa.Size = new System.Drawing.Size(81, 25);
            this.lbl_Adresa.TabIndex = 6;
            this.lbl_Adresa.Text = "Adresa:";
            // 
            // lbl_Prezime
            // 
            this.lbl_Prezime.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.lbl_Prezime.AutoSize = true;
            this.lbl_Prezime.Location = new System.Drawing.Point(28, 150);
            this.lbl_Prezime.Name = "lbl_Prezime";
            this.lbl_Prezime.Size = new System.Drawing.Size(89, 25);
            this.lbl_Prezime.TabIndex = 7;
            this.lbl_Prezime.Text = "Prezime:";
            // 
            // txt_Ime
            // 
            this.txt_Ime.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Ime.Location = new System.Drawing.Point(172, 104);
            this.txt_Ime.Name = "txt_Ime";
            this.txt_Ime.Size = new System.Drawing.Size(641, 29);
            this.txt_Ime.TabIndex = 1;
            // 
            // txt_Telefon
            // 
            this.txt_Telefon.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Telefon.Location = new System.Drawing.Point(172, 280);
            this.txt_Telefon.Name = "txt_Telefon";
            this.txt_Telefon.Size = new System.Drawing.Size(641, 29);
            this.txt_Telefon.TabIndex = 5;
            // 
            // txt_Email
            // 
            this.txt_Email.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Email.Location = new System.Drawing.Point(172, 236);
            this.txt_Email.Name = "txt_Email";
            this.txt_Email.Size = new System.Drawing.Size(641, 29);
            this.txt_Email.TabIndex = 4;
            // 
            // txt_Adresa
            // 
            this.txt_Adresa.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Adresa.Location = new System.Drawing.Point(172, 192);
            this.txt_Adresa.Name = "txt_Adresa";
            this.txt_Adresa.Size = new System.Drawing.Size(641, 29);
            this.txt_Adresa.TabIndex = 3;
            // 
            // txt_Prezime
            // 
            this.txt_Prezime.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Prezime.Location = new System.Drawing.Point(172, 148);
            this.txt_Prezime.Name = "txt_Prezime";
            this.txt_Prezime.Size = new System.Drawing.Size(641, 29);
            this.txt_Prezime.TabIndex = 2;
            // 
            // txt_Napomena
            // 
            this.txt_Napomena.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.txt_Napomena.Location = new System.Drawing.Point(172, 324);
            this.txt_Napomena.Name = "txt_Napomena";
            this.txt_Napomena.Size = new System.Drawing.Size(641, 29);
            this.txt_Napomena.TabIndex = 6;
            // 
            // btn_dodaj
            // 
            this.btn_dodaj.Anchor = System.Windows.Forms.AnchorStyles.Top;
            this.btn_dodaj.Location = new System.Drawing.Point(863, 116);
            this.btn_dodaj.Name = "btn_dodaj";
            this.btn_dodaj.Size = new System.Drawing.Size(100, 50);
            this.btn_dodaj.TabIndex = 14;
            this.btn_dodaj.TabStop = false;
            this.btn_dodaj.Text = "Dodaj";
            this.btn_dodaj.UseVisualStyleBackColor = true;
            this.btn_dodaj.Click += new System.EventHandler(this.btn_dodaj_Click);
            // 
            // dgvXML
            // 
            this.dgvXML.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.dgvXML.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvXML.Location = new System.Drawing.Point(33, 375);
            this.dgvXML.Name = "dgvXML";
            this.dgvXML.RowTemplate.Height = 31;
            this.dgvXML.Size = new System.Drawing.Size(930, 214);
            this.dgvXML.TabIndex = 17;
            this.dgvXML.RowHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dgvXML_RowHeaderMouseClick);
            // 
            // FormXml
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(11F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1000, 611);
            this.Controls.Add(this.dgvXML);
            this.Controls.Add(this.btn_dodaj);
            this.Controls.Add(this.txt_Napomena);
            this.Controls.Add(this.txt_Prezime);
            this.Controls.Add(this.txt_Adresa);
            this.Controls.Add(this.txt_Email);
            this.Controls.Add(this.txt_Telefon);
            this.Controls.Add(this.txt_Ime);
            this.Controls.Add(this.lbl_Prezime);
            this.Controls.Add(this.lbl_Adresa);
            this.Controls.Add(this.lbl_email);
            this.Controls.Add(this.lbl_telefon);
            this.Controls.Add(this.lbl_Napomena);
            this.Controls.Add(this.lbl_Naslov);
            this.Controls.Add(this.lbl_Ime);
            this.Name = "FormXml";
            this.Text = "XML adresar";
            this.Load += new System.EventHandler(this.FormXml_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dgvXML)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lbl_Ime;
        private System.Windows.Forms.Label lbl_Naslov;
        private System.Windows.Forms.Label lbl_Napomena;
        private System.Windows.Forms.Label lbl_telefon;
        private System.Windows.Forms.Label lbl_email;
        private System.Windows.Forms.Label lbl_Adresa;
        private System.Windows.Forms.Label lbl_Prezime;
        private System.Windows.Forms.TextBox txt_Ime;
        private System.Windows.Forms.TextBox txt_Telefon;
        private System.Windows.Forms.TextBox txt_Email;
        private System.Windows.Forms.TextBox txt_Adresa;
        private System.Windows.Forms.TextBox txt_Prezime;
        private System.Windows.Forms.TextBox txt_Napomena;
        private System.Windows.Forms.Button btn_dodaj;
        private System.Windows.Forms.DataGridView dgvXML;
    }
}

